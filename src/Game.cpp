#include "Game.h"

Game::Game() : m_bIsRunning(true), 
	m_Terrain(sf::Vector2f(640, 360), sf::Vector2f(1280, 720)),
	m_Soldier(sf::Vector2f(400, 300), sf::Vector2f(30, 50), sf::Vector2f(1, 1), sf::Vector2f(0, 1)) {

	m_Bombs.reserve(3);
}

Game::~Game() {

}

void Game::processKeyPress(const sf::Event &p_Event, const sf::Vector2f &p_MousePosition) {
	m_Soldier.processKeyPress(p_Event);

}

void Game::processKeyRelease(const sf::Event &p_Event) {
	switch (p_Event.key.code) {
	case sf::Mouse::Left:
		//
		break;
	case sf::Mouse::Right:
		if (m_Soldier.getBomb() != nullptr) {
			m_Bombs.push_back(m_Soldier.getBomb());
		}
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

	for (auto &i : m_Bombs) {
		i->update(p_DeltaTime);
	}

	std::vector<sf::Vector2f> collisionNormals;
	if (m_Collision(m_Terrain, m_Soldier, collisionNormals)) {
		Manifold manifold(&m_Terrain, &m_Soldier, collisionNormals, p_DeltaTime);
	}

	// Check whether any bombs have collided, with the terrain, if they have deal with it.
	for (auto iter = m_Bombs.begin(); iter != m_Bombs.end(); ++iter) {
		collisionNormals.clear();
		if (m_Collision(m_Terrain, (**iter), collisionNormals)) {
			Manifold manifold(&m_Terrain, (&**iter), collisionNormals, p_DeltaTime);

			std::vector<sf::Color> pixelColours;
			for (const auto &i : collisionNormals) {
				if (i.x >= 0 && i.x < m_Terrain.getSize().x && i.y >= 0 && i.y < m_Terrain.getSize().y - 1)
				pixelColours.push_back(m_Terrain.getPixel(i));
			}

			m_Terrain.destroyTerrain((*iter)->getPosition(), pixelColours);
			(*iter)->setHitSomething(true);
			(*iter).reset();

			if ((*iter) == nullptr || (*iter)->getHitSomething()) {
				iter = m_Bombs.erase(iter);
				break;
			}
		}
		else {
			if ((*iter) == nullptr || (*iter)->getHitSomething()) {
				iter = m_Bombs.erase(iter);
				break;
			}
		}
	}
}

void Game::draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const {
	p_Target.draw(m_Terrain);

	p_Target.draw(m_Soldier);

	for (const auto &i : m_Bombs) {
		p_Target.draw(*i);
	}
}

bool Game::isRunning() {
	return m_bIsRunning;
}

void Game::setRunningState(bool p_bRunningState) {
	m_bIsRunning = p_bRunningState;
}