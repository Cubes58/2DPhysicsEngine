/**
@file DynamicObject.h
*/
#pragma once

#include "GameObject.h"

#include <SFML/Graphics.hpp>

/*! \class DynamicObject.h
	\brief Abstract base class, which has all of the attributes and behaviour necessary to make an object dynamic.
*/

class DynamicObject : public GameObject {
protected:
	bool m_GravityOn = true; //!< Decides if gravity is on.
	bool m_DeleteMe = false; //!< Decides whether the object should be erased.

	sf::Vector2f m_Gravity; //!< Gravity for this object.
	sf::Vector2f m_Velocity; //!< Velocity of the object.
	sf::Vector2f m_Acceleration; //!< Acceleration of the object.

	DynamicObject(const sf::Vector2f &p_Position, const sf::Vector2f &p_Gravity, const sf::Vector2f &p_Size, 
		const sf::Vector2f &p_Velocity, const sf::Vector2f &p_Acceleration); //!< Constructor.
public:
	virtual void update(float p_DeltaTime) = 0; //!< Update method, updates the DynamicObject.
	virtual void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const = 0; //!< Draw method (from GameObject/sf::Drawable).

	void applyImpulse(const sf::Vector2f &p_ImpulseVector); //!< Applies an impulse vector.

	sf::Vector2f getVelocity(); //!< Returns the velocity.
	void setVelocity(const sf::Vector2f &p_Velocity); //!< Sets a new velocity value.

	sf::Vector2f getAcceleration(); //!< Returns the Acceleration.
	void setAcceleration(const sf::Vector2f &p_Accleration); //!< Sets a new acceleration value.

	bool getGravityOn(); //!< Returns whether gravity is on.
	void setGravityOn(bool p_GravityOn); //!< Sets whether gravity is active or not.

	bool getDeleteMe(); //!< Returns whether the DynamicObject should be deleted.
	void setDeleteMe(bool p_DeleteMe); //!< Sets whether the DynamicObject should be deleted.
};