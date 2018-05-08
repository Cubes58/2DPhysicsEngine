/**
@file Background.h 
@brief Manages the game's background.
*/
#pragma once

#include <SFML/Graphics.hpp>

#include "TextureManager.h"

/*! \class Background
	\brief Manages the game's background.
*/

class Background : public sf::Drawable {
private:
	sf::RectangleShape m_Background; //!< RectangleShape to draw the background.
	sf::RectangleShape m_BackgroundTint; //!< RectangleShape to give the background a tint.
	sf::Color m_TintColour; //!< Tint colour of the background tint.
public:
	/*!
		\brief Constructor.
		\param p_WindowSize the size of the window.
	*/
	Background(const sf::Vector2f &p_WindowSize);
	~Background(); //!< Destructor.

	/*!
		\brief Draw method (from Drawable).
		\param p_Target the canvas/window to draw to.
		\param p_States the state of the openGL context.
	*/
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const;
};