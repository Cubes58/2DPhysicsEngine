#include "DynamicPixel.h"

DynamicPixel::DynamicPixel(sf::Vector2f p_Position) :
	DynamicPixel(p_Position, sf::Vector2f(1, 1)) {
	
}

DynamicPixel::DynamicPixel(sf::Vector2f p_Position, sf::Vector2f p_Velocity) :
	DynamicPixel(p_Position, p_Velocity, sf::Vector2f(0, 9.81)) {
	
}

DynamicPixel::DynamicPixel(sf::Vector2f p_Position, sf::Vector2f p_Velocity, sf::Vector2f p_Acceleration) :
	DynamicPixel(p_Position, p_Velocity, p_Acceleration, sf::Color::Magenta) {
	
}

DynamicPixel::DynamicPixel(sf::Vector2f p_Position, sf::Vector2f p_Velocity, sf::Vector2f p_Acceleration, sf::Color p_Colour, sf::Vector2f p_Size) :
	DynamicObject::DynamicObject(p_Position, p_Size, p_Velocity, p_Acceleration), m_Colour(p_Colour), m_PixelRectangle(p_Size) {	
	m_PixelRectangle.setOrigin(p_Size.x / 2, p_Size.y / 2);
	m_PixelRectangle.setFillColor(m_Colour);
	m_PixelRectangle.setPosition(p_Position);

	m_LifeTime = 7.5;
}

void DynamicPixel::update(float p_DeltaTime) {
	m_TimePassed += p_DeltaTime;

	if (m_LifeTime < m_TimePassed) {
		m_DeleteMe = true;
	}

	m_Velocity = m_Velocity + m_Acceleration * p_DeltaTime;
	m_Position = m_Position + m_Velocity * p_DeltaTime;

	m_PixelRectangle.setPosition(m_Position);

	m_Acceleration.x = 0.f;
	m_Acceleration.y = 9.81f;
}

void DynamicPixel::draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const {
	p_Target.draw(m_PixelRectangle);
}

bool DynamicPixel::getDeleteMe() {
	return m_DeleteMe;
}

void DynamicPixel::setDeleteMe(bool p_DeleteMe) {
	m_DeleteMe = p_DeleteMe;
}