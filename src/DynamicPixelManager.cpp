#include "DynamicPixelManager.h"

DynamicPixelManager::DynamicPixelManager() {
	m_DynamicPixels.reserve(150);
}

DynamicPixelManager::~DynamicPixelManager() {

}

void DynamicPixelManager::cleanUpPixels() {
	m_DynamicPixels.clear();
}

void DynamicPixelManager::update(float p_DeltaTime) {
	// Erase�remove idiom.
	m_DynamicPixels.erase(std::remove_if(m_DynamicPixels.begin(), m_DynamicPixels.end(), 
		[&p_DeltaTime](std::shared_ptr<DynamicPixel> p_DynamicPixelIter)->bool {
		if (p_DynamicPixelIter->getDeleteMe()) {
			p_DynamicPixelIter.reset();
			return true;
		}
		p_DynamicPixelIter->update(p_DeltaTime);
		return false;
	}), m_DynamicPixels.end());
}

void DynamicPixelManager::draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const {
	for (const auto &i : m_DynamicPixels) {
		p_Target.draw(*i, p_States);
	}
}

void DynamicPixelManager::createClusterOfPixels(const sf::Vector2f &p_Position, std::vector<sf::Color> &p_Colours, 
	const sf::Vector2f &p_RandomXPossibleValue, const sf::Vector2f &p_RandomYPossibleValue) {
	static unsigned int s_MinimumNumberOfColours(35);

	if (p_Colours.size() <= s_MinimumNumberOfColours) {
		for (unsigned int i = 0; i < s_MinimumNumberOfColours; i++) {
			if(p_Colours.size() > 0)
				p_Colours.push_back(p_Colours[i]);
		}
	}

	for (auto &i : p_Colours) 
		createSinglePixel(p_Position, i);
}

void DynamicPixelManager::createSinglePixel(const sf::Vector2f &p_Position, sf::Color &p_Colour, 
	const sf::Vector2f &p_RandomXPossibleValue, const sf::Vector2f &p_RandomYPossibleValue) {
	float randomXVelocity = Randomiser::getInstance().getRand(p_RandomXPossibleValue.x, p_RandomXPossibleValue.y);
	float randomYVelocity = Randomiser::getInstance().getRand(p_RandomYPossibleValue.x, p_RandomYPossibleValue.y);

	std::shared_ptr<DynamicPixel> temp = std::make_shared<DynamicPixel>(p_Position, sf::Vector2f(0.0f, 98.1f), 
		sf::Vector2f(randomXVelocity, randomYVelocity), sf::Vector2f(0.0f, 98.1f), p_Colour);
	m_DynamicPixels.push_back(temp);
}

std::vector<std::shared_ptr<DynamicPixel>> & DynamicPixelManager::getDynamicPixels() {
	return m_DynamicPixels;
}