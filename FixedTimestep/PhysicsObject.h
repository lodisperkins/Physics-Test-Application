#pragma once
#include <glm/ext.hpp>
enum ShapeType
{
	PLANE = 0,
	SPHERE,
	BOX
};
class PhysicsObject
{
protected:
	PhysicsObject(ShapeType a_ShapeID) : m_shapeID(a_ShapeID) {}
	PhysicsObject();
public:
	virtual void fixedUpdate(glm::vec2 gravity, float) = 0;
	virtual void debug() = 0;
	virtual void makeGizmo() = 0;
	virtual void resetPostion() {};
protected:
	ShapeType m_shapeID;
};