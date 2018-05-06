/**
@file Bomb.h
*/
#pragma once

#include "DynamicObject.h"
#include "PixelPerfectObject.h"
#include "TextureManager.h"
#include "Team.h"

class Bomb : public DynamicObject, public PixelPerfectObject {
private:
	Team m_Team; //!< What team threw the bomb.
	float m_Damage; //!< Damage this does to a player (soldier).

	bool outOfBounds(); //!< Check whether the object is in the window.
public:
	Bomb(const Team &p_Team, const sf::Vector2f &p_Position, const sf::Vector2f &p_Gravity, const sf::Vector2f &p_Size, const sf::Vector2f &p_Velocity, 
		const sf::Vector2f &p_Acceleration = sf::Vector2f(0.0f, 98.1f)); //!< Constructor.
	~Bomb(); //!< Destructor.

	void update(float p_DeltaTime); //!< Update method, updates the object.
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const; //!< Draw method (from sf::Drawable).

	Team getTeam(); //!< Returns what team threw the bomb.a
	float getDamage(); //!< Returns the damage this item does.
};