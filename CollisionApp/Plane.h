#pragma once
#include "PhysicsObject.h"
class Plane : public PhysicsObject
{
public:
	Plane();
	Plane(glm::vec2 normal, float distance);
	~Plane();
	virtual void fixedUpdate(glm::vec2 gravity, float timestep);
	virtual void debug();
	//creates a plane with a length of 300 at the given distance form origin
	virtual void makeGizmo();
	//sets distance from origin to 0
	virtual void resetPosition();
	//returns the normal which represents the planes facing
	glm::vec2 getNormal();
	//returns distance from origin
	float getDistance();
protected:
	glm::vec2 m_normal;
	float m_distanceToOrigin;
};