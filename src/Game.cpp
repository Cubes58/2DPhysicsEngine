#include "Game.h"

Game::Game(const sf::Vector2f &p_WindowSize) : m_IsRunning(true), m_Gravity(sf::Vector2f(0.0f, 98.1f)), m_UserInterface(p_WindowSize, m_GameOverScreen),
	m_Terrain(sf::Vector2f(p_WindowSize.x / 2, p_WindowSize.y / 2), p_WindowSize), m_PlayerTurn(0), m_Background(p_WindowSize),
	m_RedSoldier(Team::RED, *TextureManager::instance().getTexture("RedSoldier"), sf::Vector2f(p_WindowSize.x / 10, p_WindowSize.y / 10), 
		m_Gravity, sf::Vector2f(25, 40), sf::Vector2f(1.0f, 1.0f), sf::Vector2f(0.0f, 1.0f)),
	m_BlueSoldier(Team::BLUE, *TextureManager::instance().getTexture("BlueSoldier"), sf::Vector2f((p_WindowSize.x / 10) * 9, p_WindowSize.y / 10), 
		m_Gravity, sf::Vector2f(25, 40), sf::Vector2f(1.0f, 1.0f), sf::Vector2f(0.0f, 1.0f)) {

	m_Bombs.reserve(3);
}

Game::~Game() {

}

void Game::processKeyPress(const sf::Event &p_Event, const sf::Vector2f &p_MousePosition) {
	if (m_GameOverScreen) {
		m_UserInterface.processKeyPress(p_Event);

		if (!m_GameOverScreen)
			m_IsRunning = false;

		return;
	}

	if(m_PlayerTurn % 2 == 0)
		m_RedSoldier.processKeyPress(p_Event, m_PlayerTurn);
	else
		m_BlueSoldier.processKeyPress(p_Event, m_PlayerTurn);
}

void Game::processKeyRelease(const sf::Event &p_Event) {
	switch (p_Event.key.code) {
	case sf::Mouse::Right:
		if (m_GameOverScreen)
			break;

		if ((m_PlayerTurn - 1) % 2 == 0) {
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
	default:
		break;
	}
}

void Game::update(float p_DeltaTime) {
	if (m_GameOverScreen) {
		if(m_RedSoldier.getScore() > m_BlueSoldier.getScore()) {
			m_UserInterface.setWinner(Team::RED);
		}
		else if (m_BlueSoldier.getScore() > m_RedSoldier.getScore()) {
			m_UserInterface.setWinner(Team::BLUE);
		}
		else {
			m_UserInterface.setWinner(Team::NONE);
		}
		return;
	}
	// Update game logic.
	m_Terrain.update(p_DeltaTime);

	m_RedSoldier.update(p_DeltaTime);
	m_BlueSoldier.update(p_DeltaTime);

	for (auto &i : m_Bombs) {
		i->update(p_DeltaTime);
	}
	m_DynamicPixelManager.update(p_DeltaTime);

	std::vector<sf::Vector2f> collisionNormals;
	// Check whether the player's have collided with the terrain.
	if (m_Collision(m_Terrain, m_RedSoldier, collisionNormals)) {
		Manifold manifold(&m_Terrain, &m_RedSoldier, collisionNormals, p_DeltaTime);
	}
	if (m_Collision(m_Terrain, m_BlueSoldier, collisionNormals)) {
		Manifold manifold(&m_Terrain, &m_BlueSoldier, collisionNormals, p_DeltaTime);
	}

	// Check whether the soldiers have collided with each other.
	if (m_Collision(m_RedSoldier, m_BlueSoldier, collisionNormals)) {
		Manifold manifold(&m_RedSoldier, &m_BlueSoldier, collisionNormals, p_DeltaTime);
	}

	// Check whether any bombs have collided, with the terrain or soldier, if they have deal with it.
	for (auto iter = m_Bombs.begin(); iter != m_Bombs.end(); ++iter) {
		float penetration(0.0f);
		if (*iter != nullptr && m_Collision(m_Terrain, (**iter), collisionNormals)) {
			std::vector<sf::Color> pixelColours;
			for (const auto &i : collisionNormals) {
				if (i.x >= 0 && i.x < m_Terrain.getSize().x && i.y >= 0 && i.y < m_Terrain.getSize().y - 1)
					pixelColours.push_back(m_Terrain.getPixel(i));
			}

			if((*iter)->getTeam() == Team::RED) 
				m_RedSoldier.addScore(Soldier::m_s_ScoreForHittingTerrain);
			else 
				m_BlueSoldier.addScore(Soldier::m_s_ScoreForHittingTerrain);

			m_DynamicPixelManager.createClusterOfPixels((*iter)->getPosition(), pixelColours);
			m_Terrain.destroyTerrain((*iter)->getPosition());
			(*iter)->setDeleteMe(true);
			(*iter).reset();
		}
		if (*iter != nullptr && m_Collision(m_RedSoldier, (**iter), penetration, collisionNormals)) {
			Manifold manifold(&m_RedSoldier, &**iter, collisionNormals, penetration);
			m_RedSoldier.setHealth(m_RedSoldier.getHealth() - (*iter)->getDamage());
			m_RedSoldier.addScore(Soldier::m_s_ScoreForHittingSoldier);
			std::vector<sf::Color> pixelColours;
			for (int i = 0; i < (int)m_RedSoldier.getHealth(); i++) {
				pixelColours.push_back(sf::Color::Red);
			}

			m_DynamicPixelManager.createClusterOfPixels(m_RedSoldier.getPosition(), pixelColours);
			(*iter)->setDeleteMe(true);
			(*iter).reset();
		}
		if (*iter != nullptr && m_Collision(m_BlueSoldier, (**iter), penetration, collisionNormals)) {
			Manifold manifold(&m_BlueSoldier, &**iter, collisionNormals, penetration);
			m_BlueSoldier.setHealth(m_BlueSoldier.getHealth() - (*iter)->getDamage());
			m_BlueSoldier.addScore(Soldier::m_s_ScoreForHittingSoldier);
			std::vector<sf::Color> pixelColours;
			for (int i = 0; i < (int)m_BlueSoldier.getHealth(); i++) {
				pixelColours.push_back(sf::Color::Red);
			}

			m_DynamicPixelManager.createClusterOfPixels(m_BlueSoldier.getPosition(), pixelColours);
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

	// Confine player's to the window.
	if (m_RedSoldier.getPosition().x < 0 || m_RedSoldier.getPosition().x > 1280) {
		m_RedSoldier.setVelocity(sf::Vector2f(-m_RedSoldier.getVelocity().x, m_RedSoldier.getVelocity().y));
	}
	if (m_RedSoldier.getPosition().y < m_RedSoldier.getSize().y / 2) {
		m_RedSoldier.setVelocity(sf::Vector2f(m_RedSoldier.getVelocity().x, -m_RedSoldier.getVelocity().y));
	}
	if (m_BlueSoldier.getPosition().x < 0 || m_BlueSoldier.getPosition().x > 1280) {
		m_BlueSoldier.setVelocity(sf::Vector2f(-m_BlueSoldier.getVelocity().x, m_BlueSoldier.getVelocity().y));
	}
	if (m_BlueSoldier.getPosition().y < m_BlueSoldier.getSize().y / 2) {
		m_BlueSoldier.setVelocity(sf::Vector2f(m_BlueSoldier.getVelocity().x, -m_BlueSoldier.getVelocity().y));
	}

	m_UserInterface.update(m_RedSoldier.getHealth(), m_BlueSoldier.getHealth());
	m_UserInterface.setText(m_UserInterface.getRedPlayerHealth(), "Health: " +  std::to_string((int)m_RedSoldier.getHealth()));
	m_UserInterface.setText(m_UserInterface.getBluePlayerHealth(), "Health: " + std::to_string((int)m_BlueSoldier.getHealth()));

	m_UserInterface.setText(m_UserInterface.getRedPlayerScore(), "Score: " + std::to_string((int)m_RedSoldier.getScore()));
	m_UserInterface.setText(m_UserInterface.getBluePlayerScore(), "Score: " + std::to_string((int)m_BlueSoldier.getScore()));

	if (m_RedSoldier.getPosition().y > 720) {
		m_RedSoldier.setLives(m_RedSoldier.getLives() - 1);
	}
	if (m_BlueSoldier.getPosition().y > 720) {
		m_BlueSoldier.setLives(m_BlueSoldier.getLives() - 1);
	}

	if (m_RedSoldier.getHealth() <= 0) {
		m_RedSoldier.setLives(m_RedSoldier.getLives() - 1);
		m_GameOverScreen = true;
	}
	else if (m_BlueSoldier.getHealth() <= 0) {
		m_BlueSoldier.setLives(m_BlueSoldier.getLives() - 1);
		m_GameOverScreen = true;
	}

	if (m_RedSoldier.getLives() <= 0) {
		m_BlueSoldier.setScore(m_BlueSoldier.getLives() * Soldier::m_s_ScoreForKillingSoldier);
		m_GameOverScreen = true;
	}
	else if (m_BlueSoldier.getLives() <= 0) {
		m_RedSoldier.setScore(m_RedSoldier.getLives() * Soldier::m_s_ScoreForKillingSoldier);
		m_GameOverScreen = true;
	}
}

void Game::draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const {
	if(m_GameOverScreen) {
		// Draw game over screen.
		p_Target.draw(m_UserInterface, p_States);
		return;
	}

	p_Target.draw(m_Background, p_States);
	p_Target.draw(m_Terrain, p_States);

	p_Target.draw(m_RedSoldier, p_States);
	p_Target.draw(m_BlueSoldier, p_States);

	for (const auto &i : m_Bombs) {
		p_Target.draw(*i, p_States);
	}

	p_Target.draw(m_DynamicPixelManager, p_States);
	p_Target.draw(m_UserInterface, p_States);
}

bool Game::isRunning() {
	return m_IsRunning;
}

void Game::setRunningState(bool p_bRunningState) {
	m_IsRunning = p_bRunningState;
}