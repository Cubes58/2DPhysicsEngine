#include "DynamicPixel.h"

DynamicPixel::DynamicPixel(const sf::Vector2f &p_Position) :
	DynamicPixel(p_Position, sf::Vector2f(1, 1)) {
	
}

DynamicPixel::DynamicPixel(const sf::Vector2f &p_Position, const sf::Vector2f &p_Velocity) :
	DynamicPixel(p_Position, p_Velocity, sf::Vector2f(0.0f, 9.81f)) {
	
}

DynamicPixel::DynamicPixel(const sf::Vector2f &p_Position, const sf::Vector2f &p_Velocity, const sf::Vector2f &p_Acceleration) :
	DynamicPixel(p_Position, sf::Vector2f(0.0f, 98.1f), p_Velocity, p_Acceleration, sf::Color::Magenta) {
	
}

DynamicPixel::DynamicPixel(const sf::Vector2f &p_Position, const sf::Vector2f &p_Gravity, const sf::Vector2f &p_Velocity,
	const sf::Vector2f &p_Acceleration, const sf::Color &p_Colour, const sf::Vector2f &p_Size) :
	DynamicObject::DynamicObject(p_Position, p_Gravity, p_Size, p_Velocity, p_Acceleration), m_Colour(p_Colour), m_PixelRectangle(p_Size) {
	m_PixelRectangle.setOrigin(p_Size.x / 2, p_Size.y / 2);
	m_PixelRectangle.setFillColor(m_Colour);
	m_PixelRectangle.setPosition(p_Position);

	m_LifeTime = 6.5;
}

void DynamicPixel::update(float p_DeltaTime) {
	if (p_DeltaTime > 0) {
		m_TimePassed += p_DeltaTime;
	}

	if (m_LifeTime < m_TimePassed) {
		m_DeleteMe = true;
	}

	m_Velocity = m_Velocity + m_Acceleration * p_DeltaTime;
	m_Position = m_Position + m_Velocity * p_DeltaTime;

	m_PixelRectangle.setPosition(m_Position);

	m_Acceleration.x = m_Gravity.x;
	m_Acceleration.y = m_Gravity.y;
}

void DynamicPixel::draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const {
	p_Target.draw(m_PixelRectangle);
}