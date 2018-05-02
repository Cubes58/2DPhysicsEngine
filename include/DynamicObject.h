#pragma once

/*!
@file DynamicObject.h
*/

#include "GameObject.h"

#include <SFML/Graphics.hpp>

class DynamicObject : public GameObject {
protected:
	bool m_GravityOn = true;
	bool m_DeleteMe = false;

	sf::Vector2f m_Gravity;
	sf::Vector2f m_Velocity;
	sf::Vector2f m_Acceleration;

	DynamicObject(const sf::Vector2f &p_Position, const sf::Vector2f &p_Gravity, const sf::Vector2f &p_Size, const sf::Vector2f &p_Velocity, const sf::Vector2f &p_Acceleration) :
		GameObject::GameObject(p_Position, p_Size), m_Gravity(p_Gravity), m_Velocity(p_Velocity), m_Acceleration(p_Acceleration) {
		
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

	bool getGravityOn() {
		return m_GravityOn;
	}

	void setGravityOn(bool p_GravityOn) {
		m_GravityOn = p_GravityOn;

		if (!m_GravityOn) {
			setAcceleration(sf::Vector2f(0.0f, 0.0f));
			setVelocity(sf::Vector2f(0.0f, 0.0f));
		}
	}

	bool getDeleteMe() {
		return m_DeleteMe;
	}

	void setDeleteMe(bool p_DeleteMe) {
		m_DeleteMe = p_DeleteMe;
	}
};