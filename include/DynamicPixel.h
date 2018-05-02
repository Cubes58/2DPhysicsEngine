#pragma once

#include "DynamicObject.h"

class DynamicPixel : public DynamicObject {
private:
	sf::RectangleShape m_PixelRectangle;

	float m_LifeTime;
	float m_TimePassed = 0;

	sf::Color m_Colour;
public:
	DynamicPixel(const sf::Vector2f &p_Position);
	DynamicPixel(const sf::Vector2f &p_Position, const sf::Vector2f &p_Velocity);
	DynamicPixel(const sf::Vector2f &p_Position, const sf::Vector2f &p_Velocity, const sf::Vector2f &p_Acceleration);
	DynamicPixel(const sf::Vector2f &p_Position, const sf::Vector2f &p_Gravity, const sf::Vector2f &p_Velocity, const sf::Vector2f &p_Acceleration,
		const sf::Color &p_Colour, const sf::Vector2f &p_Size = sf::Vector2f(1.0f, 1.0f));

	void update(float p_DeltaTime);
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const;
};