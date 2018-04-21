#include "Game.h"

Game::Game() : m_bIsRunning(true), 
	//m_DynamicPixelTest(sf::Vector2f(400, 300)), 
	m_Soldier(sf::Vector2f(400, 300), sf::Vector2f(30, 50), sf::Vector2f(1, 1), sf::Vector2f(0, 1)) {

}

Game::~Game() {

}

void Game::processKeyPress(const sf::Event &p_Event, const sf::Vector2f &p_MousePosition) {
	m_Soldier.processKeyPress(p_Event);

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
}

bool Game::isRunning() {
	return m_bIsRunning;
}

void Game::setRunningState(bool p_bRunningState) {
	m_bIsRunning = p_bRunningState;
}