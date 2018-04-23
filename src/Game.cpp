#include "Game.h"

Game::Game() : m_bIsRunning(true), 
	//m_DynamicPixelTest(sf::Vector2f(400, 300)), 
	m_Soldier(sf::Vector2f(400, 300), sf::Vector2f(30, 50), sf::Vector2f(1, 1), sf::Vector2f(0, 1)) {

	m_Bombs.reserve(2);
}

Game::~Game() {

}

void Game::processKeyPress(const sf::Event &p_Event, const sf::Vector2f &p_MousePosition) {
	m_Soldier.processKeyPress(p_Event);

}

void Game::processKeyRelease(const sf::Event &p_Event) {
	switch (p_Event.key.code) {
	case sf::Mouse::Left:

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

	std::vector<sf::Vector2f> normals;
	if (m_Collision(m_Terrain, m_Soldier, normals)) {
		Manifold manifold(&m_Terrain, &m_Soldier, normals, p_DeltaTime);
	}

	// Check whether any bombs have collided, with the terrain, if they have deal with it.
	for (auto iter = m_Bombs.begin(); iter != m_Bombs.end(); ++iter) {
		normals.clear();
		if (m_Collision(m_Terrain, (**iter), normals)) {
			Manifold manifold(&m_Terrain, (&**iter), normals, p_DeltaTime);
			m_Terrain.DestroyTerrain((*iter)->getPosition());
			(*iter)->setHitSomething(true);
			(*iter).reset();

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