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

	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const;

};