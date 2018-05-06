/**
@file Soldier.h
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

	void jump(const sf::Vector2f &p_MousePosition); //!< Makes the soldier jump, calculating the projection.
	void shoot(const sf::Vector2f &p_MousePosition); //!< Throws a bomb, calculating the projection.
public:
	Soldier(const Team &p_Team, const sf::Texture &p_Texture, const sf::Vector2f &p_Position, const sf::Vector2f &p_Gravity, const sf::Vector2f &p_Size,
		const sf::Vector2f &p_Velocity, const sf::Vector2f &p_Acceleration = sf::Vector2f(0.0f, 98.1f)); //!< Constructor.
	~Soldier(); //!< Destructor.
	
	const static float m_s_ScoreForKillingSoldier; //!< Score earned from killing a solider, with a bomb.
	const static float m_s_ScoreForHittingSoldier; //!< Score earned from hitting a solider, with a bomb.
	const static float m_s_ScoreForHittingTerrain; //!< Score earned from hitting the terrain, with a bomb.

	void processKeyPress(const sf::Event &p_Event, int &p_PlayerCounter); //!< Processes key presses, action any keys.
	void update(float p_DeltaTime); //!< Update the soldier.
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const; //!< Draw method (from DynamicObject/GameObject/sf::Drawable).

	std::shared_ptr<Bomb> getBomb(); //!< Return the bomb.
	Team getTeam(); //!< Return the team the soldier is on.

	int getLives(); //!< Return how many lives the player has.
	void setLives(int p_Lives); //!< Set how many lives the player has.

	float getScore(); //!< Returns the score.
	void setScore(float p_Score); //!< Set the player score.
	void addScore(float p_AddScore); //!< Adds to the player's score.

	float getHealth(); //!< Returns how much health the soldier has.
	void setHealth(float p_Health); //!< Sets how much health the soldier has.
};