#include "Soldier.h"

Soldier::Soldier(sf::Vector2f p_Position, sf::Vector2f p_Size, sf::Vector2f p_Velocity, sf::Vector2f p_Acceleration) 
	: DynamicObject(p_Position, p_Size, p_Velocity, p_Acceleration) {
	
	m_Shape.setSize(m_Size);
	m_Shape.setOrigin(p_Size.x / 2, p_Size.y / 2);
	m_Shape.setFillColor(sf::Color::Blue);
	m_Shape.setPosition(m_Position);
}

Soldier::~Soldier() {

}

void Soldier::update(float p_DeltaTime) {
	m_Velocity = m_Velocity + m_Acceleration * p_DeltaTime;
	m_Position = m_Position + m_Velocity * p_DeltaTime;

	m_Acceleration.x = 0.f;
	m_Acceleration.y = 9.81f;
}

void Soldier::draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const {
	p_Target.draw(m_Shape);
}