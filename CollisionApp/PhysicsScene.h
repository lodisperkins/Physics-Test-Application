#pragma once

#include <vector>
#include "PhysicsObject.h"
class PhysicsObject;

class PhysicsScene
{
private:
	bool _gravityOn = false;
public:
	PhysicsScene();
	~PhysicsScene();
	//adds actor to actor list so it can update
	void addActor(PhysicsObject* actor);
	void removeActor(PhysicsObject* actor);
	//update loop for physics scene called every frame
	void update(float dt);
	//updates the position of gizmos drawn on screen
	void updateGizmos();
	//checks the collision for all actors in scene
	void checkForCollision();
	//sets the effect of gravity in whatever direction is given
	void setGravity(const glm::vec2 gravity) { m_gravity = gravity; }
	//returns what the force of gravity as a vector
	glm::vec2 getGravity() const { return m_gravity; }
	//turns gravity on/off when called
	void toggleGravity();
	//sets the timestep for this physics scene to use
	void setTimeStep(const float timeStep) { m_timeStep = timeStep; }
	//returns this physics scenes timestep
	float getTimeStep() const { return m_timeStep; }
	//calls debug for each actor and prints how many actors are in scene
	void debugScene();
	//checks to see if two planes have collided(not yet implemented)
	static bool plane2Plane(PhysicsObject*, PhysicsObject*);
	//checks to see if a plane and a sphere have collided(not yet implemented)
	static bool plane2Sphere(PhysicsObject*, PhysicsObject*);
	//checks to see if plane and a sphere have collided(not yet implemented)
	static bool sphere2Plane(PhysicsObject*, PhysicsObject*);
	//checks to see if two spheres have collided
	static bool sphere2Sphere(PhysicsObject*, PhysicsObject*);
protected:
	glm::vec2 m_gravity{};
	float m_timeStep{};
	//a list of all actors in scene
	std::vector<PhysicsObject*> m_actors;
};

