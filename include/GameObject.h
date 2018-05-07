/**
@file GameObject.h
*/
#pragma once

#include <SFML\Graphics\Drawable.hpp>

/*! \class GameObject.h
	\brief An Abstract base class, that has the basic properties a GameObject would need.
*/

class GameObject : public sf::Drawable {
protected:
	sf::Vector2f m_Position; //!< The position of the object.
	sf::Vector2f m_Size; //!< The size of the object.

	GameObject() = default; //!< Default (synthesized) constructor.
	GameObject(const sf::Vector2f &p_Position, const sf::Vector2f &p_Size); //!< Constructor.
	~GameObject(); //!< Destructor.
public:
	virtual void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const = 0; //!< Pure virtual draw method (from sf::Drawable).

	sf::Vector2f getPosition(); //!< Return GameObject's position.
	void setPosition(const sf::Vector2f &p_Position); //!< Set GameObject's position.

	sf::Vector2f getSize(); //!< Return GameObject's size.
	void setSize(const sf::Vector2f &p_Size); //!< Set GameObject's Size.
};