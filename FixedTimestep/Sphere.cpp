#include "Sphere.h"

Sphere::Sphere(glm::vec2 position, glm::vec2 velocity, float mass, float radius, glm::vec4 colour)
{
	m_position = position;
	m_velocity = velocity;
	m_mass = mass;
	m_radius = radius;
	m_colour = colour;
}

Sphere::~Sphere()
{
}

void Sphere::makeGizmo()
{
	aie::Gizmos::add2DCircle(m_position,m_radius,21,m_colour);
}

bool Sphere::checkCollision(PhysicsObject * other)
{
	Sphere* otherSphere = (Sphere*)other;
	float distance = (float)glm::distance(m_position,otherSphere->m_position);
	std::cout << "Distance is " << distance << std::endl;
	std::cout << "current velocity is " << getVelocity().x << std::endl;
	float combinedRadius = m_radius + otherSphere->m_radius;
	if (distance < combinedRadius)
	{
		return true;
	}
	return false;
}
