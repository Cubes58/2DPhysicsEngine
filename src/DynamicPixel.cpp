#include "DynamicPixel.h"

const sf::Vector2f DynamicPixel::m_AccelerationFormula = sf::Vector2f(0.08f, -0.8f);

DynamicPixel::DynamicPixel(sf::Vector2f p_Position) :
	DynamicPixel(p_Position, sf::Vector2f(1, 1)) {
	
}

DynamicPixel::DynamicPixel(sf::Vector2f p_Position, sf::Vector2f p_Velocity) :
	DynamicPixel(p_Position, p_Velocity, sf::Vector2f(1, 1)) {
	
}

DynamicPixel::DynamicPixel(sf::Vector2f p_Position, sf::Vector2f p_Velocity, sf::Vector2f p_Acceleration) :
	DynamicPixel(p_Position, p_Velocity, p_Acceleration, sf::Color::Magenta) {
	
}

DynamicPixel::DynamicPixel(sf::Vector2f p_Position, sf::Vector2f p_Velocity, sf::Vector2f p_Acceleration, sf::Color p_Colour) :
	m_Position(p_Position), m_Velocity(p_Velocity), m_Acceleration(p_Acceleration), m_Colour(p_Colour), m_PixelRectangle(sf::Vector2f(50, 50)) {
	m_PixelRectangle.setOrigin(25, 25);
	m_PixelRectangle.setFillColor(m_Colour);
	//m_PixelRectangle.setFillColor(sf::Color::Red);
	m_PixelRectangle.setPosition(m_Position);
}

void DynamicPixel::update(sf::Time p_DeltaTime) {
	//Update the rectangle's position - based on Euler. (1000)
	m_PreviousPosition = m_Position;
	// Standard Euler.
	m_Acceleration.x = m_AccelerationFormula.x * m_Velocity.x;
	m_Acceleration.y = m_AccelerationFormula.y * m_Velocity.y;

	m_Velocity.x = m_Velocity.x + (m_Acceleration.x * ((float)p_DeltaTime.asMilliseconds() / 100));
	m_Velocity.y = m_Velocity.y + (m_Acceleration.y * ((float)p_DeltaTime.asMilliseconds() / 100));

	m_Position.x = m_Position.x + m_Velocity.x * ((float)p_DeltaTime.asMilliseconds() / 100);
	m_Position.y = m_Position.y + m_Velocity.y * ((float)p_DeltaTime.asMilliseconds() / 100);

	m_PixelRectangle.setPosition(m_Position);
}

void DynamicPixel::draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const {
	p_Target.draw(m_PixelRectangle);
}

sf::Vector2f DynamicPixel::getPosition() {
	return m_Position;
}

void DynamicPixel::setPosition(const sf::Vector2f &p_Position) {
	m_PreviousPosition = m_Position;
	m_Position = p_Position;
}

sf::Vector2f DynamicPixel::getPreviousPosition() {
	return m_PreviousPosition;
}

sf::Vector2f DynamicPixel::getVelocity() {
	return m_Velocity;
}

void DynamicPixel::setVelocity(const sf::Vector2f &p_Velocity) {
	m_Velocity = p_Velocity;
}

sf::Vector2f DynamicPixel::getAcceleration() {
	return m_Acceleration;
}

void DynamicPixel::setAcceleration(const sf::Vector2f &p_Accleration) {
	m_Acceleration = p_Accleration;
}

sf::Color DynamicPixel::getColour() {
	return m_Colour;
}

void DynamicPixel::setColour(const sf::Color &p_Colour) {
	m_Colour = p_Colour;
}

float DynamicPixel::getFriction() {
	return m_Friction;
}

void DynamicPixel::setFriction(float p_Friction) {
	m_Friction = p_Friction;
}

float DynamicPixel::getRestitution() {
	return m_Restitution;
}

void DynamicPixel::setRestitution(float p_Restitution) {
	m_Restitution = p_Restitution;
}