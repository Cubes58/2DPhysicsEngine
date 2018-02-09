#pragma once

#include <vector>

#include <SFML\Graphics.hpp>
//#include <SFML\Graphics\Image.hpp>

#include "Vector2D.h"
#include "TextureManager.h"
#include "DynamicPixel.h"

class Terrain : public sf::Drawable {
private:
	sf::Image m_StaticTerrain;
	std::vector<DynamicPixel> m_DynamicPixels;
public:
	Terrain();

	sf::Color getPixel(unsigned int p_XPosition, unsigned int p_YPosition);
	void removePixel(unsigned int p_XPosition, unsigned int p_YPosition);
	void addPixel(unsigned int p_XPosition, unsigned int p_YPosition, sf::Color p_Colour);

	void update();	//Maybe add a bool that checks if the image/texture has been updated. 'Cause updating the image is expensive.
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const;
};