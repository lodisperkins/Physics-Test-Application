#pragma once
#include "PhysicsObject.h" 
#include <iostream>
#include <vector>
#include "Rigidbody.h"	
class PhysicsScene
{
public:
	PhysicsScene();
	~PhysicsScene();

	void addActor(PhysicsObject* actor);
	void removeActor(PhysicsObject* actor);
	void update(float dt);
	void updateGizmos();
	void debugScene();
	void setGravity(const glm::vec2 gravity);
	void setTimeStep(const float timeStep);
	float getTimeStop() const;
protected:
	glm::vec2 m_gravity;
	float m_timeStep;
	std::vector<PhysicsObject*> m_actors;
};