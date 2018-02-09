#include "DynamicPixel.h"

DynamicPixel::DynamicPixel(sf::Vector2u p_Position) :
	DynamicPixel(p_Position, sf::Vector2f(1, 1), sf::Vector2f(1, 1)) {

}

DynamicPixel::DynamicPixel(sf::Vector2u p_Position, sf::Vector2f p_Velocity) :
	DynamicPixel(p_Position, p_Velocity, sf::Vector2f(1, 1)) {

}

DynamicPixel::DynamicPixel(sf::Vector2u p_Position, sf::Vector2f p_Velocity, sf::Vector2f p_Acceleration) :
	m_Position(p_Position), m_Velocity(p_Velocity), m_Acceleration(p_Acceleration) {

}