#include "Game.h"

Game::Game() : m_bIsRunning(true), m_DynamicPixelTest(sf::Vector2f(400, 300), sf::Vector2f(1, 1)) {

}

Game::~Game() {

}

void Game::processKeyPress(sf::Keyboard::Key p_Key) {
	//Process user input.
	for (float i = 0; i < 600; i++) {
		for (float j = 0; j < 100; j++) {
			m_Terrain.removePixel(sf::Vector2f(i, j));
		}
	}
}

void Game::processKeyRelease(sf::Keyboard::Key p_Key) {

}

void Game::update(sf::Time p_DeltaTime) {
	//Update game logic.
	m_Terrain.update(p_DeltaTime);

	m_DynamicPixelTest.update(p_DeltaTime);

	/* DETECT COLLISION??? */
	std::vector<sf::Vector2f> temp;
	if (Collision(m_Terrain, m_Soldier, temp)) {
		//COLLISION DETECTED.
		Manifold manifold(&m_Terrain, &m_Soldier);
	}
}

void Game::draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const {
	p_Target.draw(m_Terrain);

	p_Target.draw(m_DynamicPixelTest);
}

bool Game::isRunning() {
	return m_bIsRunning;
}

void Game::setRunningState(bool p_bRunningState) {
	m_bIsRunning = p_bRunningState;
}

bool Game::Collision(Terrain t, Soldier s, std::vector<sf::Vector2f> &p_CollisionPoints) {
	bool bCollision(false);

	sf::Vector2f startPoint = sf::Vector2f(s.getPosition().x - (s.getSize().x / 2), s.getPosition().y - (s.getSize().y / 2));
	sf::Vector2f endPoint = sf::Vector2f(s.getPosition().x + (s.getSize().x / 2), s.getPosition().y + (s.getSize().y / 2));

	for (int i = startPoint.x; i <= endPoint.x; i++) {
		for (int j = startPoint.y; j <= endPoint.y; j++) {
			if (t.getPixel(sf::Vector2f(i, j)) != sf::Color::Transparent) {
				p_CollisionPoints.push_back(sf::Vector2f(i, j));
				//Check to see if the soldier's pixel[s] are transparent.
				bCollision = true;
			}
		}
	}
	
	return bCollision;
}

// Maybe change texture to bool, and return true or false based on whether it's there or not