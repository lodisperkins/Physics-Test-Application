#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "PhysicsScene.h"
#include "Sphere.h"
class FixedTimestepApp : public aie::Application {
public:

	FixedTimestepApp();
	virtual ~FixedTimestepApp();
	PhysicsScene* m_physicsScene;
	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();
	void setupContinuousDemo(glm::vec2 startPos, float angle, float startSpeed, float gravity);
protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};