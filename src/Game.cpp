#include "Game.h"

Game::Game() : m_bIsRunning(true), m_Gravity(sf::Vector2f(0.0f, 98.1f)), m_UserInterface(sf::Vector2f(1280, 720)),
	m_Terrain(sf::Vector2f(640, 360), sf::Vector2f(1280, 720)), m_PlayerTurn(0),
	m_RedSoldier(Team::RED, sf::Vector2f(400, 300), m_Gravity, sf::Vector2f(25, 40), sf::Vector2f(1.0f, 1.0f), sf::Vector2f(0.0f, 1.0f)), 
	m_BlueSoldier(Team::BLUE, sf::Vector2f(400, 300), m_Gravity, sf::Vector2f(25, 40), sf::Vector2f(1.0f, 1.0f), sf::Vector2f(0.0f, 1.0f)) {

	m_Bombs.reserve(3);
}

Game::~Game() {

}

void Game::processKeyPress(const sf::Event &p_Event, const sf::Vector2f &p_MousePosition) {
	if(m_PlayerTurn % 2 == 0)
		m_RedSoldier.processKeyPress(p_Event, m_PlayerTurn);
	else
		m_BlueSoldier.processKeyPress(p_Event, m_PlayerTurn);
}

void Game::processKeyRelease(const sf::Event &p_Event) {
	switch (p_Event.key.code) {
	case sf::Mouse::Left:
		break;
	case sf::Mouse::Right:
		if (m_PlayerTurn % 2 == 0) {
			if (m_RedSoldier.getBomb() != nullptr) {
				m_Bombs.push_back(m_RedSoldier.getBomb());
			}
		}
		else {
			if (m_BlueSoldier.getBomb() != nullptr) {
				m_Bombs.push_back(m_BlueSoldier.getBomb());
			}
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
	m_UserInterface.update(m_RedSoldier.getHealth(), m_BlueSoldier.getHealth());

	m_RedSoldier.update(p_DeltaTime);
	m_BlueSoldier.update(p_DeltaTime);

	for (auto &i : m_Bombs) {
		i->update(p_DeltaTime);
	}

	m_DynamicPixelManager.update(p_DeltaTime);

	std::vector<sf::Vector2f> collisionNormals;
	collisionNormals.clear();
	if (m_Collision(m_Terrain, m_RedSoldier, collisionNormals)) {
		Manifold manifold(&m_Terrain, &m_RedSoldier, collisionNormals, p_DeltaTime);
	}
	collisionNormals.clear();
	if (m_Collision(m_Terrain, m_BlueSoldier, collisionNormals)) {
		Manifold manifold(&m_Terrain, &m_BlueSoldier, collisionNormals, p_DeltaTime);
	}

	// Check whether any bombs have collided, with the terrain, if they have deal with it.
	for (auto iter = m_Bombs.begin(); iter != m_Bombs.end(); ++iter) {
		collisionNormals.clear();
		if (m_Collision(m_Terrain, (**iter), collisionNormals)) {
			std::vector<sf::Color> pixelColours;
			for (const auto &i : collisionNormals) {
				if (i.x >= 0 && i.x < m_Terrain.getSize().x && i.y >= 0 && i.y < m_Terrain.getSize().y - 1)
					pixelColours.push_back(m_Terrain.getPixel(i));
			}

			m_DynamicPixelManager.createClusterOfPixels((*iter)->getPosition(), pixelColours);
			m_Terrain.destroyTerrain((*iter)->getPosition());
			(*iter)->setDeleteMe(true);
			(*iter).reset();
		}
		if ((*iter) == nullptr || (*iter)->getDeleteMe()) {
			iter = m_Bombs.erase(iter);
			break;
		}
	}

	// Check collision/resolve collision between the Dynamic pixels, and terrain.
	for (auto &i : m_DynamicPixelManager.getDynamicPixels()) {
		collisionNormals.clear();
		if(m_Collision(m_Terrain, *i, collisionNormals)) {
			Manifold manifold(&m_Terrain, &*i, collisionNormals, p_DeltaTime);
		}
	}

	if (m_RedSoldier.getPosition().x < 0 || m_RedSoldier.getPosition().x > 1280) {
		m_RedSoldier.setVelocity(sf::Vector2f(-m_RedSoldier.getVelocity().x, m_RedSoldier.getVelocity().y));
	}
	if (m_RedSoldier.getPosition().y < m_RedSoldier.getSize().y / 2) {
		m_RedSoldier.setVelocity(sf::Vector2f(m_RedSoldier.getVelocity().x, -m_RedSoldier.getVelocity().y));
	}
}

void Game::draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const {
	p_Target.draw(m_Terrain);

	p_Target.draw(m_RedSoldier);
	p_Target.draw(m_BlueSoldier);

	for (const auto &i : m_Bombs) {
		p_Target.draw(*i);
	}

	p_Target.draw(m_DynamicPixelManager);
	p_Target.draw(m_UserInterface);
}

bool Game::isRunning() {
	return m_bIsRunning;
}

void Game::setRunningState(bool p_bRunningState) {
	m_bIsRunning = p_bRunningState;
}