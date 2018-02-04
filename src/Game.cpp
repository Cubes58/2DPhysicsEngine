#include "Game.h"

Game::Game() {

}

Game::~Game() {

}

void Game::processKeyPress(sf::Keyboard::Key p_Key) {
	//Process user input.

}

void Game::processKeyRelease(sf::Keyboard::Key p_Key) {

}

void Game::update(sf::Time p_DeltaTime) {
	//Update game logic.

}

void Game::draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const {
	//target.draw();
}

bool Game::isRunning() {
	return m_bIsRunning;
}

void Game::setRunningState(bool p_bRunningState) {
	m_bIsRunning = p_bRunningState;
}