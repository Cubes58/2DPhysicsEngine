/**
@file GameObject.h
@brief An Abstract base class, that has the basic properties a GameObject would need.
*/
#pragma once

#include <SFML\Graphics\Drawable.hpp>

/*! \class GameObject
	\brief An Abstract base class, that has the basic properties a GameObject would need.
*/

class GameObject : public sf::Drawable {
protected:
	sf::Vector2f m_Position; //!< The position of the object.
	sf::Vector2f m_Size; //!< The size of the object.

	GameObject() = default; //!< Default (synthesized) constructor.

	/*!
		\brief Constructor.
		\param p_Position the starting position of the object.
		\param p_Size the starting size of the object.
	*/
	GameObject(const sf::Vector2f &p_Position, const sf::Vector2f &p_Size);
	~GameObject(); //!< Destructor.
public:
	/*!
		\brief Pure virtual draw method (from Drawable).
		\param p_Target the canvas/window to draw to.
		\param p_States the state[s] of the OpenGL context.
	*/
	virtual void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const = 0;

	sf::Vector2f getPosition(); //!< Return GameObject's position.

	/*!
		\brief Set GameObject's position.
		\param p_Position the new position to set the game object's position to.
	*/
	void setPosition(const sf::Vector2f &p_Position);

	sf::Vector2f getSize(); //!< Return GameObject's size.

	/*!
		\brief  Set GameObject's Size.
		\param p_Size the new size, to set as the object's size.
	*/
	void setSize(const sf::Vector2f &p_Size);
};