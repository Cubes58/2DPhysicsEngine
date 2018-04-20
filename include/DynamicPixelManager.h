#pragma once

#include <vector>
#include <memory>

#include "DynamicPixel.h"

class DynamicPixelManager : public sf::Drawable {
private:
	std::vector<DynamicPixel> m_DynamicPixels;

	void cleanUpPixels();
public:
	DynamicPixelManager();

	void update(float p_DeltaTime);
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const;

	void createClusterOfPixels(const sf::Color &p_Colour);
	void createSinglePixel(const sf::Color &p_colour, int p_NumberOfPixels);
};