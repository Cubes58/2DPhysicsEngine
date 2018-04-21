#include "DynamicPixelManager.h"

DynamicPixelManager::DynamicPixelManager() {
	m_DynamicPixels.reserve(30);
}

DynamicPixelManager::~DynamicPixelManager() {

}

void DynamicPixelManager::cleanUpPixels() {
	m_DynamicPixels.clear();
}

void DynamicPixelManager::update(float p_DeltaTim) {
	for (auto &i : m_DynamicPixels) {
		i.update(p_DeltaTim);
		
		if (i.getPosition().x < 0 || i.getPosition().x >= 800 || i.getPosition().y < 0 || i.getPosition().y > 600) {
			// Delete them? Or if they're near 0 (top of the screen), reverse their velocity?
		}
	}
}

void DynamicPixelManager::draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const {
	for (auto &i : m_DynamicPixels) {
		i.draw(p_Target, p_States);
	}
}

void DynamicPixelManager::createClusterOfPixels(const sf::Vector2f &p_Position, const sf::Color &p_Colour, int p_NumberOfPixels) {
	for (int i = 0; i < p_NumberOfPixels; i++) {
		createSinglePixel(p_Position, p_Colour);
	}
}

void DynamicPixelManager::createSinglePixel(const sf::Vector2f &p_Position, const sf::Color &p_Colour) {
	float randomXVelocity = m_RandomNumberGenerator.getRand(-100, 100);
	float randomYVelocity = m_RandomNumberGenerator.getRand(-100, 100);

	DynamicPixel temp(p_Position, sf::Vector2f(randomXVelocity, randomYVelocity), sf::Vector2f(0, 98.1), p_Colour);
	m_DynamicPixels.push_back(temp);
}
