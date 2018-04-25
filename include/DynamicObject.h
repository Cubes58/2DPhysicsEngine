/*! 
@file DynamicObject.h
*/

#pragma once

#include "GameObject.h"

#include <SFML/Graphics.hpp>

class DynamicObject : public GameObject {
protected:
	bool m_GravityOn = false;

	sf::Vector2f m_Velocity;
	sf::Vector2f m_Acceleration;

	DynamicObject(const  sf::Vector2f &p_Position, const sf::Vector2f &p_Size, const sf::Vector2f &p_Velocity, const sf::Vector2f &p_Acceleration) :
		GameObject::GameObject(p_Position, p_Size), m_Velocity(p_Velocity), m_Acceleration(p_Acceleration) {
		
	}
public:
	virtual void update(float p_DeltaTime) = 0;
	virtual void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const = 0;

	void applyImpulse(const sf::Vector2f &p_ImpulseVector) {
		m_Velocity += p_ImpulseVector;
	}

	sf::Vector2f getVelocity() {
		return m_Velocity;
	}
	void setVelocity(const sf::Vector2f &p_Velocity) {
		m_Velocity = p_Velocity;
	}

	sf::Vector2f getAcceleration() {
		return m_Acceleration;
	}
	void setAcceleration(const sf::Vector2f &p_Accleration) {
		m_Acceleration = p_Accleration;
	}
};