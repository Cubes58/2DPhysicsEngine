#include "Game.h"

Game::Game() : m_bIsRunning(true), 
	//m_DynamicPixelTest(sf::Vector2f(400, 300)), 
	m_Soldier(sf::Vector2f(400, 300), sf::Vector2f(60, 100), sf::Vector2f(1, 1), sf::Vector2f(0, 1)),
	m_Rocket(sf::Vector2f(400, 300), sf::Vector2f(30, 30), sf::Vector2f(1, 1), sf::Vector2f(0, 1)) {

	// Add subscribers.
	m_MouseSubscriber.attach(&m_Soldier);
}

Game::~Game() {

}

void Game::processKeyPress(sf::Event p_Event) {
	switch (p_Event.key.code) {
	case sf::Mouse::Left:
		m_MouseSubscriber.notify(MouseClickEvent(MouseButton::LEFT, p_Event.mouseButton.x, p_Event.mouseButton.y));
		break;
	case sf::Mouse::Right:
		m_MouseSubscriber.notify(MouseClickEvent(MouseButton::RIGHT, p_Event.mouseButton.x, p_Event.mouseButton.y));
		break;
	case sf::Mouse::Middle:
		m_MouseSubscriber.notify(MouseClickEvent(MouseButton::WHEEL, p_Event.mouseButton.x, p_Event.mouseButton.y));
		break;

	default:
		break;
	}
}

void Game::processKeyRelease(sf::Event p_Event) {
	switch (p_Event.key.code) {
	case sf::Mouse::Left:

		break;
	case sf::Mouse::Right:

		break;

	case sf::Mouse::Middle:

		break;

	default:
		break;
	}
}

void Game::update(float p_DeltaTime) {
	// Update game logic.
	m_Terrain.update(p_DeltaTime);

	//m_DynamicPixelTest.update(p_DeltaTime);

	m_Soldier.update(p_DeltaTime);

	std::vector<sf::Vector2f> normals;
	if (m_Collision(m_Terrain, m_Soldier, normals)) {
		//COLLISION DETECTED.
		Manifold manifold(&m_Terrain, &m_Soldier, normals, p_DeltaTime);
	}

}

void Game::draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const {
	p_Target.draw(m_Terrain);

	p_Target.draw(m_Soldier);
	//p_Target.draw(m_DynamicPixelTest);
}

bool Game::isRunning() {
	return m_bIsRunning;
}

void Game::setRunningState(bool p_bRunningState) {
	m_bIsRunning = p_bRunningState;
}