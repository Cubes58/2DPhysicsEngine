#include "DynamicPixel.h"

DynamicPixel::DynamicPixel(sf::Vector2f p_Position) :
	DynamicPixel(p_Position, sf::Vector2f(1, 1)) {
	
}

DynamicPixel::DynamicPixel(sf::Vector2f p_Position, sf::Vector2f p_Velocity) :
	DynamicPixel(p_Position, p_Velocity, sf::Vector2f(1, 1)) {
	
}

DynamicPixel::DynamicPixel(sf::Vector2f p_Position, sf::Vector2f p_Velocity, sf::Vector2f p_Acceleration) :
	DynamicPixel(p_Position, p_Velocity, p_Acceleration, sf::Color::Magenta) {
	
}

DynamicPixel::DynamicPixel(sf::Vector2f p_Position, sf::Vector2f p_Velocity, sf::Vector2f p_Acceleration, sf::Color p_Colour, sf::Vector2f p_Size) :
	DynamicObject::DynamicObject(p_Position, p_Size, p_Velocity, p_Acceleration), m_Colour(p_Colour), m_PixelRectangle(sf::Vector2f(50, 50)) {	
	
	m_PixelRectangle.setOrigin(25, 25);
	m_PixelRectangle.setFillColor(m_Colour);
	//m_PixelRectangle.setFillColor(sf::Color::Red);
	m_PixelRectangle.setPosition(m_Position);
	//m_Position = sf::Vector2f(0, 0);
}

void DynamicPixel::update(float p_DeltaTime) {
	m_Velocity = m_Velocity + m_Acceleration * p_DeltaTime;
	m_Position = m_Position + m_Velocity * p_DeltaTime;

	m_PixelRectangle.setPosition(m_Position);

	m_Acceleration.x = 0.f;
	m_Acceleration.y = 9.81f;
}

void DynamicPixel::draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const {
	p_Target.draw(m_PixelRectangle);
}