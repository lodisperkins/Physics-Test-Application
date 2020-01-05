#pragma once
#include "PhysicsObject.h"
#include <iostream>

class RigidBody :
	public PhysicsObject
{
public:
	RigidBody(ShapeType shapeID, glm::vec2 position,
		glm::vec2 velocity, float rotation, float mass);
	~RigidBody();

	virtual void fixedUpdate(glm::vec2 gravity, float timeStep);
	virtual void debug();
	//applies a force with the magnitude and direction given 
	void applyForce(glm::vec2 force);
	//applies a force using an actor to apply an equal an opposite force to both actors
	void applyForceToActor(RigidBody* actor2, glm::vec2 force);
	//applies the force and direction to the actors based on velocity and elasticity
	void resolveCollision(RigidBody * actor2);
	//checks to see if this actor collided with another
	virtual bool checkCollision(PhysicsObject* pOther) = 0;

	glm::vec2 getPosition() { return m_position; }
	float getRotation() { return m_rotation; }
	//prevents the magnitude of this actors velocity from increasing past this number
	void setMaxSpeed(float speed);
	glm::vec2 getVelocity() { return m_velocity; }
	float getMass() { return m_mass; }

protected:
	glm::vec2 m_position{};
	glm::vec2 m_velocity{};
	float m_mass;
	float m_rotation;
};