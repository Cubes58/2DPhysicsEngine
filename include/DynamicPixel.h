#pragma once

#include <SFML\Graphics.hpp>

class DynamicPixel {
private:
	sf::Vector2u m_Position;
	sf::Vector2f m_Velocity;
	sf::Vector2f m_Acceleration;
	sf::Vector2f m_PreviousPosition;

	float m_Colour;
	float m_Friction;
	float m_Restitution;
public:
	DynamicPixel(sf::Vector2u p_Position);
	DynamicPixel(sf::Vector2u p_Position, sf::Vector2f p_Velocity);
	DynamicPixel(sf::Vector2u p_Position, sf::Vector2f p_Velocity, sf::Vector2f p_Acceleration);

	//Draw pixel sized squares, which zoom around based on their velocity, and acceleration.
};