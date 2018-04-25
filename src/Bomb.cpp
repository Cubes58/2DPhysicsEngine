#include "Bomb.h"

Bomb::Bomb(const sf::Vector2f &p_Position, const sf::Vector2f &p_Size, const sf::Vector2f &p_Velocity, const sf::Vector2f &p_Acceleration)
	: DynamicObject(p_Position, p_Size, p_Velocity, p_Acceleration), PixelPerfectObject(p_Position, "./assets/Textures/Bomb.png") {

	m_Shape.setSize(m_Size);
	m_Shape.setOrigin(p_Size.x / 2, p_Size.y / 2);
	m_Shape.setTexture(TextureManager::instance().getTexture("Bomb"));
	m_Shape.setPosition(m_Position);
}

Bomb::~Bomb() {

}

void Bomb::update(float p_DeltaTime) {
	m_Velocity = m_Velocity + m_Acceleration * p_DeltaTime;
	m_Position = m_Position + m_Velocity * p_DeltaTime;

	m_Shape.setPosition(m_Position);

	m_Acceleration.x = 0.0f;
	m_Acceleration.y = 98.1f;
}

void Bomb::draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const {
	p_Target.draw(m_Shape);
}

bool Bomb::getHitSomething() {
	return m_HitSomething;
}

void Bomb::setHitSomething(bool p_HitSomething) {
	m_HitSomething = p_HitSomething;
}