/**
@file DynamicObject.h
@brief Abstract base class, which has all of the attributes and behavior necessary to make an object dynamic.
*/
#pragma once

#include "GameObject.h"

#include <SFML/Graphics.hpp>

/*! \class DynamicObject
	\brief Abstract base class, which has all of the attributes and behavior necessary to make an object dynamic.
*/

class DynamicObject : public GameObject {
protected:
	bool m_GravityOn = true; //!< Decides if gravity is on.
	bool m_DeleteMe = false; //!< Decides whether the object should be erased.

	sf::Vector2f m_Gravity; //!< Gravity for this object.
	sf::Vector2f m_Velocity; //!< Velocity of the object.
	sf::Vector2f m_Acceleration; //!< Acceleration of the object.

	/*!
		\brief Constructor.
		\param p_Position the starting position.
		\param p_Gravity the world's gravity, that'll affect the objects acceleration.
		\param p_Size the size.
		\param p_Velocity the object's velocity.
		\param p_Acceleration the object's starting acceleration.
	*/
	DynamicObject(const sf::Vector2f &p_Position, const sf::Vector2f &p_Gravity, const sf::Vector2f &p_Size, 
		const sf::Vector2f &p_Velocity, const sf::Vector2f &p_Acceleration);
public:
	/*!
		\brief Pure virtual update method, updates the DynamicObject. Every Dynamic Object child class has to implement an update.
		\param p_DeltaTime the time step. The amount of time passed, since this was last called.
	*/
	virtual void update(float p_DeltaTime) = 0;

	/*! 
		\brief Pure virtual draw method (from GameObject/Drawable).
		\param p_Target the canvas/window to draw to.
		\param p_States the state[s] of the OpenGL context.
	*/
	virtual void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const = 0;

	/*!
		\brief Applies an impulse vector.
		\param p_ImpulseVector the impulse vector to apply to the object.
	*/
	void applyImpulse(const sf::Vector2f &p_ImpulseVector); 

	sf::Vector2f getVelocity(); //!< Returns the velocity.

	/*!
		\brief Sets a new velocity value.
		\param p_Velocity the new velocity value.
	*/
	void setVelocity(const sf::Vector2f &p_Velocity);

	sf::Vector2f getAcceleration(); //!< Returns the Acceleration.

	/*!
		\brief Sets a new acceleration value.
		\param p_Acceleration the new acceleration value.
	*/
	void setAcceleration(const sf::Vector2f &p_Acceleration);

	bool getGravityOn(); //!< Returns whether gravity is on.

	/*!
		\brief Sets whether gravity is active or not.
		\param p_GravityOn sets whether the gravity should be enabled or not.
	*/
	void setGravityOn(bool p_GravityOn); 

	bool getDeleteMe(); //!< Returns whether the DynamicObject should be deleted.

	/*!
		\brief
		\param p_DeleteMe sets whether the DynamicObject should be deleted.
	*/
	void setDeleteMe(bool p_DeleteMe);
};