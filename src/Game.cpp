#include "Game.h"

Game::Game() : m_bIsRunning(true), 
	m_DynamicPixelTest(sf::Vector2f(400, 300)), 
	m_Soldier(sf::Vector2f(400, 300), sf::Vector2f(100, 100), sf::Vector2f(1, 1), sf::Vector2f(0, 1)),
	m_Rocket(sf::Vector2f(400, 300), sf::Vector2f(100, 100), sf::Vector2f(1, 1), sf::Vector2f(0, 1)) {

}

Game::~Game() {

}

void Game::processKeyPress(sf::Keyboard::Key p_Key) {

}

void Game::processKeyRelease(sf::Keyboard::Key p_Key) {

}

void Game::update(float p_DeltaTime) {
	// Update game logic.
	m_Terrain.update(p_DeltaTime);

	m_DynamicPixelTest.update(p_DeltaTime);

	//if (falling)
	m_Soldier.update(p_DeltaTime);
	
	// Explode.
	int numberOfPoints = 100;
	float twoPi = 6.28;

	float radius = 40.0f;
	sf::Vector2f position = sf::Vector2f(1200, 800);
	sf::Vector2f px;
	for (float theta = 0; theta < twoPi; theta += (twoPi / numberOfPoints)) {
		px.x = position.x + cosf(theta) * radius;
		px.y = position.y + sinf(theta) * radius;

		m_Terrain.removePixel(px);
	}


	std::vector<sf::Vector2f> normals;
	if (m_Collision(m_Terrain, m_Soldier, normals)) {
		//COLLISION DETECTED.
		Manifold manifold(&m_Terrain, &m_Soldier, normals, p_DeltaTime);
		//falling = false;
	}

}

void Game::draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const {
	p_Target.draw(m_Terrain);

	p_Target.draw(m_Soldier);
	p_Target.draw(m_DynamicPixelTest);
}

bool Game::isRunning() {
	return m_bIsRunning;
}

void Game::setRunningState(bool p_bRunningState) {
	m_bIsRunning = p_bRunningState;
}