/**
@file Background.h 
*/
#pragma once

#include <SFML/Graphics.hpp>

#include "TextureManager.h"

/*! \class Background.h
\brief Manages the game's background.
*/

class Background : public sf::Drawable {
private:
	sf::RectangleShape m_Background; //!< RectangleShape to draw the background.
	sf::RectangleShape m_BackgroundTint; //!< RectangleShape to give the background a tint.
	sf::Color m_TintColour; //!< Tint colour of the background tint.
public:
	Background(const sf::Vector2f &p_WindowSize); //!< Constructor.
	~Background(); //!< Destructor.

	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const; //!< Draw method (from sf::Drawable).
};