#include "Rigidbody.h"
#include <iostream>
RigidBody::RigidBody()
{
}

RigidBody::RigidBody(ShapeType shapeID, glm::vec2 position, glm::vec2 velocity, float rotation, float mass)
{
	m_shapeID = shapeID;
	m_position = position;
	m_velocity = velocity;
	m_rotation = rotation;
	m_mass = mass;
}

RigidBody::~RigidBody()
{
}

void RigidBody::fixedUpdate(glm::vec2 gravity, float timestep)
{
	applyForce(gravity * m_mass*timestep);
	m_position += m_velocity * timestep;
}

void RigidBody::debug()
{
}

void RigidBody::applyForce(glm::vec2 force)
{
	m_velocity += force / m_mass;
}

void RigidBody::applyForceToActor(RigidBody * actor2, glm::vec2 force)
{
	actor2->applyForce(force);
	
	applyForce(-force);
	std::cout << " New Velocity is " << m_velocity.x << std::endl;
}
