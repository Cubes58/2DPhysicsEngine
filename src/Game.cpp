#include "Game.h"

Game::Game() : m_bIsRunning(true), 
	m_DynamicPixelTest(sf::Vector2f(400, 300)), m_Soldier(sf::Vector2f(400, 300), sf::Vector2f(100, 100), sf::Vector2f(1, 1), sf::Vector2f(0, 1)) {

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

	//m_DynamicPixelTest.update(p_DeltaTime);

	if (falling)
		m_Soldier.update(p_DeltaTime);
	
	/* DETECT COLLISION??? */
	std::vector<sf::Vector2f> normals;
	if (Collision(m_Terrain, m_Soldier, normals)) {
		//COLLISION DETECTED.
		Manifold manifold(&m_Terrain, &m_Soldier, normals);
		falling = false;
	}
	if (Collision(m_Terrain, m_DynamicPixelTest, normals)) {
		//COLLISION DETECTED.
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

bool Game::Collision(Terrain t, Soldier s, std::vector<sf::Vector2f> &p_CollisionPoints) {
	bool bCollision(false);

	sf::Vector2f startPoint = sf::Vector2f(s.getPosition().x - (s.getSize().x / 2), s.getPosition().y - (s.getSize().y / 2));
	sf::Vector2f endPoint = sf::Vector2f(s.getPosition().x + (s.getSize().x / 2), s.getPosition().y + (s.getSize().y / 2));

	/* Have to check that i and j are larger than 0, and that they're smaller than the height/width. */

	for (int i = startPoint.x; (i > 0 && i < t.getSize().x) && i <= endPoint.x; i++) {
		for (int j = startPoint.y; (j > 0 && j < t.getSize().y) && j <= endPoint.y; j++) {
			if (t.getPixel(sf::Vector2f(i, j)) != sf::Color::Transparent) {
				p_CollisionPoints.push_back(sf::Vector2f(i, j));

				sf::Color colour = t.getPixel(sf::Vector2f(i, j));
				if (colour == sf::Color::Transparent) {
					bCollision = false;
				}
				else// Check to see if the soldier's pixel[s] are transparent.
				bCollision = true;

				colour = sf::Color::Transparent;

				if (bCollision) {
					;
					colour = sf::Color::Transparent;
				}
			}
		}
	}
	
	return bCollision;
}

bool Game::Collision(Terrain t, DynamicPixel d, std::vector<sf::Vector2f> &p_CollisionPoints) {
	bool bCollision(false);

	sf::Vector2f startPoint = sf::Vector2f(d.getPosition().x - (d.getSize().x / 2), d.getPosition().y - (d.getSize().y / 2));
	sf::Vector2f endPoint = sf::Vector2f(d.getPosition().x + (d.getSize().x / 2), d.getPosition().y + (d.getSize().y / 2));

	for (int i = startPoint.x; (i > 0 && i < t.getSize().x) && i <= endPoint.x; i++) {
		for (int j = startPoint.y; (j > 0 && j < t.getSize().y) && j <= endPoint.y; j++) {
			if (t.getPixel(sf::Vector2f(i, j)) != sf::Color::Transparent) {
				p_CollisionPoints.push_back(sf::Vector2f(i, j));
				// Check to see if the soldier's pixel[s] are transparent.
				bCollision = true;
			}
		}
	}

	return bCollision;
}