#include "Plane.h"

Plane::Plane(): PhysicsObject(ShapeType::PLANE)
{
}

Plane::Plane(glm::vec2 normal, float distance): PhysicsObject(ShapeType::PLANE)
{
	m_normal = normal;
	m_distanceToOrigin = distance;
}

Plane::~Plane()
{
}

void Plane::fixedUpdate(glm::vec2 gravity, float timestep)
{
}

void Plane::debug()
{
}

void Plane::makeGizmo()
{
	float lineSegmentLength = 300;
	glm::vec2 centerPoint = m_normal * m_distanceToOrigin;
	glm::vec2 parallel(m_normal.y, -m_normal.x);
	glm::vec4 colour(1,1,1,1);
	glm::vec2 start = centerPoint + (parallel * lineSegmentLength);
	glm::vec2 end = centerPoint - (parallel * lineSegmentLength);
	aie::Gizmos::add2DLine(start, end, colour);
}

void Plane::resetPosition()
{
	m_distanceToOrigin = 0;
}

glm::vec2 Plane::getNormal()
{
	return m_normal;
}

float Plane::getDistance()
{
	return m_distanceToOrigin;
}
