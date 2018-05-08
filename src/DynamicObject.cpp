#include "DynamicObject.h"

DynamicObject::DynamicObject(const sf::Vector2f &p_Position, const sf::Vector2f &p_Gravity, const sf::Vector2f &p_Size, const sf::Vector2f &p_Velocity, const sf::Vector2f &p_Acceleration) :
	GameObject::GameObject(p_Position, p_Size), m_Gravity(p_Gravity), m_Velocity(p_Velocity), m_Acceleration(p_Acceleration) {

}

void DynamicObject::applyImpulse(const sf::Vector2f &p_ImpulseVector) {
	m_Velocity += p_ImpulseVector;
}

sf::Vector2f DynamicObject::getVelocity() {
	return m_Velocity;
}
void DynamicObject::setVelocity(const sf::Vector2f &p_Velocity) {
	m_Velocity = p_Velocity;
}

sf::Vector2f DynamicObject::getAcceleration() {
	return m_Acceleration;
}
void DynamicObject::setAcceleration(const sf::Vector2f &p_Acceleration) {
	m_Acceleration = p_Acceleration;
}

bool DynamicObject::getGravityOn() {
	return m_GravityOn;
}

void DynamicObject::setGravityOn(bool p_GravityOn) {
	m_GravityOn = p_GravityOn;

	if (!m_GravityOn) {
		setAcceleration(sf::Vector2f(0.0f, 0.0f));
		setVelocity(sf::Vector2f(0.0f, 0.0f));
	}
}

bool DynamicObject::getDeleteMe() {
	return m_DeleteMe;
}

void DynamicObject::setDeleteMe(bool p_DeleteMe) {
	m_DeleteMe = p_DeleteMe;
}