#include "DynamicPixelManager.h"

DynamicPixelManager::DynamicPixelManager() {
	m_DynamicPixels.reserve(50);
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
	}

	for (const auto &i : m_DynamicPixels)
		i->update(p_DeltaTime);
}

void DynamicPixelManager::draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const {
	for (const auto &i : m_DynamicPixels)
		i->draw(p_Target, p_States);
}

void DynamicPixelManager::createClusterOfPixels(const sf::Vector2f &p_Position, const std::vector<sf::Color> &p_Colours, 
	const sf::Vector2f &p_RandomXPossibleValue, const sf::Vector2f &p_RandomYPossibleValue) {
	for (const auto &i : p_Colours) 
		createSinglePixel(p_Position, i);
}

void DynamicPixelManager::createSinglePixel(const sf::Vector2f &p_Position, const sf::Color &p_Colour, 
	const sf::Vector2f &p_RandomXPossibleValue, const sf::Vector2f &p_RandomYPossibleValue) {
	float randomXVelocity = Randomiser::getInstance().getRand(p_RandomXPossibleValue.x, p_RandomXPossibleValue.y);
	float randomYVelocity = Randomiser::getInstance().getRand(p_RandomYPossibleValue.x, p_RandomYPossibleValue.y);

	std::shared_ptr<DynamicPixel> temp = std::make_shared<DynamicPixel>(p_Position, sf::Vector2f(randomXVelocity, randomYVelocity), sf::Vector2f(0.0f, 98.1f), p_Colour);
	m_DynamicPixels.push_back(temp);
}
