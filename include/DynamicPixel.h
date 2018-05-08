/**
@file DynamicPixel.h
@brief A pixel sized rectangle, with a timer for deletion, which represents a dynamic pixel.
*/
#pragma once

#include "DynamicObject.h"

/*! \class DynamicPixel
	\brief A pixel sized rectangle, with a timer for deletion, which represents a dynamic pixel.
*/

class DynamicPixel : public DynamicObject {
private:
	sf::RectangleShape m_PixelRectangle; //!< Pixel sized rectangle.

	float m_LifeTime; //!< How long the DynamicPixel should survive.
	float m_TimePassed = 0; //!< How long the DynamicPixel has been alive.

	sf::Color m_Colour; //!< Colour of the DynamicPixel.
public:
	/*!
		\brief Constructor.
		\param p_Position the starting position, of the dynamic pixel object.
	*/
	DynamicPixel(const sf::Vector2f &p_Position);

	/*!
		\brief Constructor.
		\param p_Position the starting position, of the dynamic pixel object.
		\param p_Velocity the starting velocity of the object.
	*/
	DynamicPixel(const sf::Vector2f &p_Position, const sf::Vector2f &p_Velocity); 

	/*!
		\brief Constructor.
		\param p_Position the starting position, of the dynamic pixel object.
		\param p_Velocity the starting velocity of the object.
		\param p_Acceleration the starting acceleration of the object.
	*/
	DynamicPixel(const sf::Vector2f &p_Position, const sf::Vector2f &p_Velocity, const sf::Vector2f &p_Acceleration); 

	/*!
		\brief Constructor.
		\param p_Position the starting position, of the dynamic pixel object.
		\param p_Gravity the gravity that affect the dynamic pixel.
		\param p_Velocity the starting velocity of the object.
		\param p_Acceleration the starting acceleration of the object.
		\param p_Colour the colour of the pixel.
		\param p_Size the size of the dynamic pixel (default 1 by 1).
	*/
	DynamicPixel(const sf::Vector2f &p_Position, const sf::Vector2f &p_Gravity, const sf::Vector2f &p_Velocity, const sf::Vector2f &p_Acceleration,
		const sf::Color &p_Colour, const sf::Vector2f &p_Size = sf::Vector2f(1.0f, 1.0f)); 

	/*!
		\brief Updates the DynamicPixel (properties).
		\param p_DeltaTime the amount of time passed since this was last called.
	*/
	void update(float p_DeltaTime); 

	/*!
		\brief Draw method (from DynamicObject/GameObject/Drawable). 
		\param p_Target the canvas/window to draw to.
		\param p_States the state[s] of the OpenGL context.
	*/
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const;
};