#include "PhysicsScene.h"
#include <list>
#include "RigidBody.h"
#include <glm/detail/func_geometric.inl>
#include "Sphere.h"
typedef bool(*fn)(PhysicsObject*, PhysicsObject*);

static fn collisionFunctionArray[] = 
{
	PhysicsScene::plane2Plane,PhysicsScene::plane2Sphere,
	PhysicsScene::sphere2Plane,PhysicsScene::sphere2Sphere
};

PhysicsScene::PhysicsScene()
{
	setTimeStep(.01f);
	setGravity(glm::vec2(0, 0));
}

PhysicsScene::~PhysicsScene()
{
	for (auto pActor : m_actors)
	{
		delete pActor;
	}
}

void PhysicsScene::addActor(PhysicsObject* actor)
{
	m_actors.push_back(actor);
}

void PhysicsScene::removeActor(PhysicsObject* actor)
{
	int actorPos = -1;
	for(int i = 0; i < m_actors.size(); i++)
	{
		if (m_actors[i] == actor)
		{
			actorPos = i;
		}
	}

	if (actorPos != -1)
		m_actors.erase(m_actors.begin()+actorPos);
}

void PhysicsScene::update(float dt)
{
	static std::list<PhysicsObject*> dirty;

	
	//update physics at a fixed time step
	static float accumulatedTime = 0.0f;
	accumulatedTime += dt;

	while (accumulatedTime >= m_timeStep)
	{
		for (auto pActor : m_actors)
		{
			pActor->fixedUpdate(m_gravity, m_timeStep);
		}

		accumulatedTime -= m_timeStep;

		// check for collisions
		/*for (auto pActor : m_actors)
		{
			for (auto pOther: m_actors)
			{
				if (pActor == pOther)
					continue;
				if (std::find(dirty.begin(), dirty.end(), pActor) != dirty.end() &&
					std::find(dirty.begin(), dirty.end(), pOther) != dirty.end())
					continue;

				RigidBody* pRigid = dynamic_cast<RigidBody*>(pActor);
				if (pRigid->checkCollision(pOther) == true)
				{
					pRigid->applyForceToActor(
						dynamic_cast<RigidBody*>(pOther),
						pRigid->getVelocity() * pRigid->getMass());
					dirty.push_back(pRigid);
					dirty.push_back(pOther);
				}
			}
		}
		dirty.clear();*/
		checkForCollision();
	}
}

void PhysicsScene::updateGizmos()
{
	for (auto pActor : m_actors)
	{
		pActor->makeGizmo();
	}
}

void PhysicsScene::checkForCollision()
{
	int actorCount = m_actors.size();
	for (int outer = 0; outer < actorCount - 1; outer++)
	{
		for (int inner = outer + 1; inner < actorCount; inner++)
		{
			PhysicsObject*object1 = m_actors[outer];
			PhysicsObject* object2 = m_actors[inner];
			int shapeID1 = object1->getShapeID();
			int shapeID2 = object2->getShapeID();
			int functionIDX = (shapeID1*SHAPE_COUNT)+shapeID2;
			fn collisionFunctionPtr = collisionFunctionArray[functionIDX-1];
			if (collisionFunctionPtr != nullptr)
			{
				collisionFunctionPtr(object1, object2);
			}
		}
	}
}

void PhysicsScene::toggleGravity()
{
	if (_gravityOn)
	{
		setGravity(glm::vec2(0, 0));
		_gravityOn = false;
	}
	else
	{
		setGravity(glm::vec2(0, -100));
		_gravityOn = true;
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

bool PhysicsScene::plane2Plane(PhysicsObject *, PhysicsObject *)
{
	return false;
}

bool PhysicsScene::plane2Sphere(PhysicsObject *, PhysicsObject *)
{
	return false;
}

bool PhysicsScene::sphere2Plane(PhysicsObject *, PhysicsObject *)
{
	return false;
}

bool PhysicsScene::sphere2Sphere(PhysicsObject * obj1, PhysicsObject *obj2)
{
	Sphere *sphere1 = dynamic_cast<Sphere*>(obj1);
	Sphere *sphere2 = dynamic_cast<Sphere*>(obj2);
	if (sphere1 != nullptr && sphere2 != nullptr)
	{
		if (sphere1->checkCollision(sphere2))
		{
			sphere1->resolveCollision(sphere2);
			return true;
		}
	}
	return false;
}


