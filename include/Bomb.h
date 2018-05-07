/**
@file Bomb.h
@brief Bomb class.
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
	/*!
	\brief Constructor.
	\param p_Team the team the object belongs to.
	\param p_Position the original position of the bomb.
	\param p_Gravity the gravity that affects the object's acceleration.
	\param p_Size size of the object.
	\param p_Velocity initial velocity of the bomb.
	\param p_Acceleration initial acceleration of the bomb.
	*/
	Bomb(const Team &p_Team, const sf::Vector2f &p_Position, const sf::Vector2f &p_Gravity, const sf::Vector2f &p_Size, const sf::Vector2f &p_Velocity, 
		const sf::Vector2f &p_Acceleration = sf::Vector2f(0.0f, 98.1f)); //!< 
	~Bomb(); //!< Destructor.

	/*!
		\brief  Update method, updates the object.
		\param p_DeltaTime the time step. The amount of time passed, since this was last called.
	*/
	void update(float p_DeltaTime);

	/*!
		\brief  Draw method (from sf::Drawable).
		\param p_Target the canvas/window to draw to.
		\param p_States the state[s] of the OpenGL context.
	*/
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const;

	Team getTeam(); //!< Returns what team threw the bomb.a
	float getDamage(); //!< Returns the damage this item does.
};