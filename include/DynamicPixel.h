#pragma once

#include "DynamicObject.h"

class DynamicPixel : public DynamicObject {
private:
	sf::RectangleShape m_PixelRectangle;

	float m_LifeTime;
	sf::Color m_Colour;
public:
	DynamicPixel(sf::Vector2f p_Position);
	DynamicPixel(sf::Vector2f p_Position, sf::Vector2f p_Velocity);
	DynamicPixel(sf::Vector2f p_Position, sf::Vector2f p_Velocity, sf::Vector2f p_Acceleration);
	DynamicPixel(sf::Vector2f p_Position, sf::Vector2f p_Velocity, sf::Vector2f p_Acceleration, sf::Color p_Colour, sf::Vector2f p_Size = sf::Vector2f(1.0f, 1.0f));

	void update(float p_DeltaTime);
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const;
};