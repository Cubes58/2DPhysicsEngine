#include "DynamicPixelManager.h"

DynamicPixelManager::DynamicPixelManager() {
	m_DynamicPixels.reserve(40);
}

void DynamicPixelManager::cleanUpPixels() {
	m_DynamicPixels.clear();
}

void DynamicPixelManager::update(float p_DeltaTim) {
	for (auto &i : m_DynamicPixels) {
		// Use a random to decide the vector.
		// Use a random class?
		//i.applyImpulse();


		if (i.getPosition().x < 0 || i.getPosition().x >= 800 || i.getPosition().y < 0 || i.getPosition().y > 600) {

		}
	}
}

void DynamicPixelManager::draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const {
	for (auto &i : m_DynamicPixels) {
		i.draw(p_Target, p_States);
	}
}

void DynamicPixelManager::createClusterOfPixels(const sf::Color &p_Colour) {

}

void DynamicPixelManager::createSinglePixel(const sf::Color &p_Colour, int p_NumberOfPixels) {
	// Create temp, to add.
	//DynamicPixel temp();
	// 
	// Use a random to decide the vector.
	// Use a random class?
	for (int i = 0; i < p_NumberOfPixels; i++)
		;//m_DynamicPixels.push_back(temp);
}
