/**
@file DynamicPixel.h
*/
#pragma once

#include "DynamicObject.h"

class DynamicPixel : public DynamicObject {
private:
	sf::RectangleShape m_PixelRectangle; //!< Pixel sized rectangle.

	float m_LifeTime; //!< How long the DynamicPixel should survive.
	float m_TimePassed = 0; //!< How long the DynamicPixel has been alive.

	sf::Color m_Colour; //!< Colour of the DynamicPixel.
public:
	DynamicPixel(const sf::Vector2f &p_Position); //!< Constructor.
	DynamicPixel(const sf::Vector2f &p_Position, const sf::Vector2f &p_Velocity); //!< Constructor.
	DynamicPixel(const sf::Vector2f &p_Position, const sf::Vector2f &p_Velocity, const sf::Vector2f &p_Acceleration); //!< Constructor.
	DynamicPixel(const sf::Vector2f &p_Position, const sf::Vector2f &p_Gravity, const sf::Vector2f &p_Velocity, const sf::Vector2f &p_Acceleration,
		const sf::Color &p_Colour, const sf::Vector2f &p_Size = sf::Vector2f(1.0f, 1.0f)); //!< Constructor.

	void update(float p_DeltaTime); //!< Updates the DynamicPixel.
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const; //!< Draw method (from DynamicObject/GameObject/sf::Drawable). 
};