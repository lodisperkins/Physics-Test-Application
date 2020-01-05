#pragma once
#include "RigidBody.h"
#include "glm/vec4.hpp"

class Sphere :
public RigidBody
{
public:
	Sphere(glm::vec2 position, glm::vec2 velocity, 
		float mass, float radius, glm::vec4 colour);
	~Sphere();
	//draws a circle on screen
	virtual void makeGizmo();
	//checks the collision between this sphere and another object
	virtual bool checkCollision(PhysicsObject* pOther);
	//sets the velocity of this sphere to 0
	void stopVelocity();
	float getRadius() { return m_radius; }
	glm::vec4 getColour() { return m_colour; }
	
protected:
	float m_radius;
	glm::vec4 m_colour;
};
