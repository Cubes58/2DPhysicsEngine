#pragma once

#include <vector>
#include <memory>

#include "DynamicPixel.h"
#include "Randomiser.h"

class DynamicPixelManager : public sf::Drawable {
private:
	std::vector<std::shared_ptr<DynamicPixel>> m_DynamicPixels;

	void cleanUpPixels();
public:
	DynamicPixelManager();
	~DynamicPixelManager();

	void update(float p_DeltaTime);
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const;

	void createClusterOfPixels(const sf::Vector2f &p_Position, const std::vector<sf::Color> &p_Colours, 
		const sf::Vector2f &p_RandomXPossibleValue = sf::Vector2f(-50, 50), const sf::Vector2f &p_RandomYPossibleValue = sf::Vector2f(-50, 50));
	void createSinglePixel(const sf::Vector2f &p_Position, const sf::Color &p_colour, 
		const sf::Vector2f &p_RandomXPossibleValue = sf::Vector2f(-50, 50), const sf::Vector2f &p_RandomYPossibleValue = sf::Vector2f(-50, 50));
};