#include "FixedTimestampStudyApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

FixedTimestampStudyApp::FixedTimestampStudyApp() {

}

FixedTimestampStudyApp::~FixedTimestampStudyApp() {

}

bool FixedTimestampStudyApp::startup() {
	
	// increase the 2d line count to maximize the number of obj we can draw
	aie::Gizmos::create(255U, 255U, 65535U, 65535U);
	
	
	m_2dRenderer = new aie::Renderer2D();

	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	m_physicsScene = new PhysicsScene();
	
	m_physicsScene->setTimeStep(0.01f);

	//Creates two new balls for the scene
	ball = new Sphere(glm::vec2(-20, 0), glm::vec2(0, 0), 4.0f, 4, glm::vec4(1, 0, 0, 1));
	ball2 = new Sphere(glm::vec2(20, 0), glm::vec2(0, 0), 4.0f, 4, glm::vec4(0, 1, 0, 1));
	//adds balls as actors to the scene
	m_physicsScene->addActor(ball);
	m_physicsScene->addActor(ball2);
	//gives the balls a starting velocity
	ball->applyForce(glm::vec2(50, 20));
	ball2->applyForce(glm::vec2(-40, 20));
	return true;
}

 void FixedTimestampStudyApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void FixedTimestampStudyApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	aie::Gizmos::clear();

	m_physicsScene->update(deltaTime);
	m_physicsScene->updateGizmos();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
	//all input for controlling the directioj of the red ball
	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		ball->applyForce(glm::vec2(10, 0));
	}
	if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		ball->applyForce(glm::vec2(0, -10));
	}
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		ball->applyForce(glm::vec2(0, 10));
	}
	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		ball->applyForce(glm::vec2(-10, 0));
	}
	//inut for turning gravity on/off
	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	{
		m_physicsScene->toggleGravity();
	}
	//checks to see if balls are in the bound of the screen
	if (ball->getPosition().x >= 100 || ball->getPosition().x <= -100 || ball->getPosition().y >= 50 || ball->getPosition().y <= -50)
	{
		ball->applyForce((-ball->getVelocity())*=10);
	}
	if (ball2->getPosition().x >= 100 || ball2->getPosition().x <= -100 || ball2->getPosition().y >= 50 || ball2->getPosition().y <= -50)
	{
		ball2->applyForce((-ball2->getVelocity()) *= 10);
	}
	//clamps the velocity vector of the balls to be no more than 70
	ball->setMaxSpeed(70);
	ball2->setMaxSpeed(70);
}

void FixedTimestampStudyApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	static float aspectRatio = 16 / 9.0f;
	aie::Gizmos::draw2D(glm::ortho<float>(-100, 100, 
		-100 / aspectRatio, 100 / aspectRatio, -1.0f, 1.0f));
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);
	m_2dRenderer->drawText(m_font, "Use WASD to move the red ball", 0, 60);
	m_2dRenderer->drawText(m_font, "Use SPACE to toggle gravity on/off", 0, 30);
	// done drawing sprites
	m_2dRenderer->end();
}