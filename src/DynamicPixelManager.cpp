#include "DynamicPixelManager.h"

DynamicPixelManager::DynamicPixelManager() {
	m_DynamicPixels.reserve(30);
}

DynamicPixelManager::~DynamicPixelManager() {

}

void DynamicPixelManager::cleanUpPixels() {
	m_DynamicPixels.clear();
}

void DynamicPixelManager::update(float p_DeltaTime) {
	/*
	auto i = m_DynamicPixels.begin();
	while(i != m_DynamicPixels.end()) {
		if ((*i)->getDeleteMe()) {
			i->reset();
			m_DynamicPixels.erase(i++);
		}
		else {
			(*i)->update(p_DeltaTime);
			++i;
		}
	}*/

	for (auto i = m_DynamicPixels.begin(); i != m_DynamicPixels.end(); ++i) {		
		if ((*i)->getDeleteMe()) {
			m_DynamicPixels.erase(i);
			break;
		}
		//(i->getPosition().x < 0 || i->getPosition().x >= 800 || i->getPosition().y < 0 || i->getPosition().y > 600)
	}

	for (const auto &i : m_DynamicPixels)
		i->update(p_DeltaTime);
}

void DynamicPixelManager::draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const {
	for (const auto &i : m_DynamicPixels) {
		i->draw(p_Target, p_States);
	}
}

void DynamicPixelManager::createClusterOfPixels(const sf::Vector2f &p_Position, const sf::Color &p_Colour, int p_NumberOfPixels) {
	for (int i = 0; i < p_NumberOfPixels; i++) {
		createSinglePixel(p_Position, p_Colour);
	}
}

void DynamicPixelManager::createSinglePixel(const sf::Vector2f &p_Position, const sf::Color &p_Colour) {
	float randomXVelocity = m_RandomNumberGenerator.getRand(-50, 50);
	float randomYVelocity = m_RandomNumberGenerator.getRand(-50, 50);

	std::shared_ptr<DynamicPixel> temp = std::make_shared<DynamicPixel>(p_Position, sf::Vector2f(randomXVelocity, randomYVelocity), sf::Vector2f(0, 98.1), p_Colour);
	m_DynamicPixels.push_back(temp);
}
