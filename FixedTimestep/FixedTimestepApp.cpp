#include "FixedTimestepApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <Gizmos.h>
FixedTimestepApp::FixedTimestepApp() {

}

FixedTimestepApp::~FixedTimestepApp() {

}

bool FixedTimestepApp::startup() {
	aie::Gizmos::create(255U, 255U, 65535U, 65535U);
	m_2dRenderer = new aie::Renderer2D();
	
	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	m_physicsScene = new PhysicsScene();
	m_physicsScene->setGravity(glm::vec2(0, 0));
	m_physicsScene->setTimeStep(0.01f);
	setupContinuousDemo(glm::vec2(-40, 0), 40, 45, 10);

	return true;
}

void FixedTimestepApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void FixedTimestepApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();
	//aie::Gizmos::clear();
	m_physicsScene->update(deltaTime);
	m_physicsScene->updateGizmos();
	
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void FixedTimestepApp::draw() {

	// wipe the screen to the background colour
	clearScreen();
	
	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	static float aspectRatio = 16 / 9.f;
	aie::Gizmos::draw2D(glm::ortho<float>(-100, 100, -100 / aspectRatio, 100 / aspectRatio, -1.0f, 1.0f));
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}

void FixedTimestepApp::setupContinuousDemo(glm::vec2 startPos, float angle, float startSpeed, float gravity)
{
	float t = 0;
	float tStep = 0.05f;
	float radius = 1.0f;
	int segments = 12;
	glm::vec4 colour = glm::vec4(1, 1, 0, 1);

	float xPos;
	float yPos;

	while (t <= 10)
	{
		// calculate the x,y position of the projectile at time t
		xPos = startPos.x + (startSpeed*glm::cos(angle)) * t;
		yPos = startPos.y + (startSpeed*glm::sin(angle)) * t + .5 * -gravity * t * t;






		aie::Gizmos::add2DCircle(glm::vec2(xPos, yPos), radius, segments, colour);
		t += tStep;
	}
}
