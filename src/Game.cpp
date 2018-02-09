#include "Game.h"

Game::Game() : m_bIsRunning(true) {

}

Game::~Game() {

}

void Game::processKeyPress(sf::Keyboard::Key p_Key) {
	//Process user input.
	for (int i = 0; i < 600; i++) {
		for (int j = 0; j < 100; j++) {
			m_Terrain.removePixel(i, j);
		}
	}
	//m_Terrain.removePixel( );
}

void Game::processKeyRelease(sf::Keyboard::Key p_Key) {

}

void Game::update(sf::Time p_DeltaTime) {
	//Update game logic.
	m_Terrain.update();
}

void Game::draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const {
	p_Target.draw(m_Terrain);
}

bool Game::isRunning() {
	return m_bIsRunning;
}

void Game::setRunningState(bool p_bRunningState) {
	m_bIsRunning = p_bRunningState;
}