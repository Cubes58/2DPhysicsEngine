#pragma once

#include <SFML/Graphics.hpp>

#include "TextureManager.h"

class Background : public sf::Drawable {
private:
	sf::RectangleShape m_Background;
	sf::RectangleShape m_BackgroundTint;
	sf::Color m_TintColour;
public:
	Background(const sf::Vector2f &p_WindowSize);
	~Background();

	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const;
};