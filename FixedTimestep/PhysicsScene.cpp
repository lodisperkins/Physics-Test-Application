#include "PhysicsScene.h"

PhysicsScene::PhysicsScene()
{
}

PhysicsScene::~PhysicsScene()
{
	for (auto pActor : m_actors)
	{
		delete pActor;
	}
}

void PhysicsScene::addActor(PhysicsObject * actor)
{
	m_actors.push_back(actor);
}

void PhysicsScene::removeActor(PhysicsObject * actor)
{
	int iterator = -1;
	for (int i = 0; i < m_actors.size(); i++)
	{
		if (m_actors[i] == actor)
		{
			iterator = i;
			break;
		}
	}
	std::vector< PhysicsObject *>::iterator actorPosition= m_actors.begin() + iterator;
	m_actors.erase(actorPosition);
}

void PhysicsScene::update(float dt)
{
	static std::vector<PhysicsObject*> dirty;
	static float accumulatedTime = 0.0f;
	accumulatedTime += dt;
	while (accumulatedTime >= m_timeStep)
	{
		for (auto pActor : m_actors)
		{
			pActor->fixedUpdate(m_gravity, m_timeStep);
		}
		accumulatedTime -= m_timeStep;
		// sphere collision check
		for (auto pActor : m_actors)
		{
			for (auto pOther : m_actors)
			{
				if (pActor == pOther)
				{
					continue;
				}
				std::vector< PhysicsObject *>::iterator pActorIter = std::find(dirty.begin(), dirty.end(), pActor);
				std::vector< PhysicsObject *>::iterator pOtherIter = std::find(dirty.begin(), dirty.end(), pOther);
				if (pActorIter != dirty.end() && pOtherIter != dirty.end())
				{
					continue;
				}
				RigidBody* pRigid = dynamic_cast<RigidBody*>(pActor);
				if (pRigid->checkCollision(pOther) == true)
				{
					pRigid->applyForceToActor(dynamic_cast<RigidBody*>(pOther), pRigid->getVelocity()*pRigid->getMass());
					dirty.push_back(pRigid);
					dirty.push_back(pOther);
				}
			}
			dirty.clear();
		}
	}
}

void PhysicsScene::updateGizmos()
{
	for (auto pActor : m_actors)
	{
		pActor->makeGizmo();
	}
}

void PhysicsScene::debugScene()
{
	int count = 0;
	for (auto pActor : m_actors)
	{
		std::cout << count << " : ";
		pActor->debug();
		count++;
	}
}

void PhysicsScene::setGravity(const glm::vec2 gravity)
{
	m_gravity = gravity;
}

void PhysicsScene::setTimeStep(const float timeStep)
{
	m_timeStep = timeStep;
}

float PhysicsScene::getTimeStop() const
{
	return m_timeStep;
}


