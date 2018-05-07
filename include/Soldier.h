/**
@file Soldier.h
@brief A class that has the properties and methods to create a soldier.
*/
#pragma once

#include <cmath>
#include <memory>

#include "TextureManager.h"
#include "DynamicObject.h"
#include "Bomb.h"
#include "Team.h"

class Soldier : public DynamicObject, public PixelPerfectObject {
private:
	std::shared_ptr<Bomb> m_Bomb; //!< A bomb, generated when the player fires one.

	int m_Lives; //!< Number of lives the soldier has.
	float m_Score; //!< How much score the player has.
	float m_Health; //!< How much health the soldier has.
	Team m_Team; //!< The team the solider is on.

	/*!
		\brief Makes the soldier jump, calculating the projection.
		\param p_MousePosition position of the mouse, when the player clicked to jump.
	*/
	void jump(const sf::Vector2f &p_MousePosition);

	/*!
		\brief Throws a bomb, calculating the projection.
		\param p_MousePosition position of the mouse, when the player clicked to jump.
	*/
	void shoot(const sf::Vector2f &p_MousePosition);
public:
	/*!
		\brief Constructor.
		\param p_Team the team of the soldier.
		\param p_Texture the texture the soldier will use.
		\param p_Position spawn position of the solider.
		\param p_Gravity gravity that'll affect the soldier.
		\param p_Size size of the soldier.
		\param p_Velocity current movement speed of the soldier.
		\param p_Acceleration the movement speed increase of the soldier.
	*/
	Soldier(const Team &p_Team, const sf::Texture &p_Texture, const sf::Vector2f &p_Position, const sf::Vector2f &p_Gravity, const sf::Vector2f &p_Size,
		const sf::Vector2f &p_Velocity, const sf::Vector2f &p_Acceleration = sf::Vector2f(0.0f, 98.1f));
	~Soldier(); //!< Destructor.
	
	const static float m_s_ScoreForKillingSoldier; //!< Score earned from killing a solider, with a bomb.
	const static float m_s_ScoreForHittingSoldier; //!< Score earned from hitting a solider, with a bomb.
	const static float m_s_ScoreForHittingTerrain; //!< Score earned from hitting the terrain, with a bomb.

	/*!
		\brief Processes key presses, action any keys.
		\param p_Event the user input.
		\param p_PlayerCounter the counter that manages whose turn it is.
	*/
	void processKeyPress(const sf::Event &p_Event, int &p_PlayerCounter);

	/*!
		\brief Update the soldier.
		\param p_DeltaTime the time step. The amount of time passed, since this was last called.
	*/
	void update(float p_DeltaTime);

	/*!
		\brief Draw method (from DynamicObject/GameObject/sf::Drawable).
		\param p_Target the canvas/window to draw to.
		\param p_States the state of the openGL context.
	*/
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const;

	std::shared_ptr<Bomb> getBomb(); //!< Return the bomb.
	Team getTeam(); //!< Return the team the soldier is on.

	int getLives(); //!< Return how many lives the player has.

	/*!
		\brief Set how many lives the player has.
		\param p_Lives number of lives to set the soldier to.
	*/
	void setLives(int p_Lives);

	float getScore(); //!< Returns the score.

	/*!
		\brief Set the player score.
		\param p_Score sets the score.
	*/
	void setScore(float p_Score);
	/*!
		\brief Adds to the player's score.
		\param p_AddScore amount of score to add to the current score.
	*/
	void addScore(float p_AddScore);

	float getHealth(); //!< Returns how much health the soldier has.

	/*!
		\brief Sets how much health the soldier has.
		\param p_Health the number to set the soldier's health to.
	*/
	void setHealth(float p_Health);
};