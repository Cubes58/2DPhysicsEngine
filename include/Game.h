/**
@file Game.h
@brief Holds all of the information about the game components in the game and allows rendering, updating, and key pressed.
*/
#pragma once

#include <memory>

#include <SFML\Graphics.hpp>

#include "TextureManager.h"
#include "Collision.h"
#include "Manifold.h"
#include "AudioManager.h"
#include "UserInterface.h"
#include "Background.h"
#include "Terrain.h"
#include "DynamicPixelManager.h"
#include "Soldier.h"
#include "Bomb.h"

class Game : public sf::Drawable {
private:
	sf::Vector2f m_Gravity; //!< World's gravity.

	AudioManager m_AudioManager;
	Background m_Background; //!< Background object, to manage the background.
	Collision m_Collision; //!< Collision object, to check for collisions.
	Terrain m_Terrain; //!< Terrain object, for the terrain.
	DynamicPixelManager m_DynamicPixelManager; //!< Dynamic pixel manager object, to manage the dynamic pixels.
	UserInterface m_UserInterface; //!< User interface object, to manage the HUD.

	Soldier m_RedSoldier; //!< Red soldier (player 1).
	Soldier m_BlueSoldier; //!< Blue soldier (player 2).

	int m_PlayerTurn; //!< Turn manager.
	std::vector<std::shared_ptr<Bomb>> m_Bombs; //!< Vector of shared pointers, pointing to bombs, to keep track of them (the bombs).
	
	bool m_GameOverScreen = false; //!< Manages game over screen.
	bool m_IsRunning; //!< Manages whether the game is running, or not.
public:
	Game(const sf::Vector2f &p_WindowSize); //!< Constructor.
	~Game(); //!< Destructor.

	/*! 
		\brief Action any key presses.
		\param p_Event the player's input.
		\param p_MousePosition the position of the mouse, when the event was triggered.
	*/
	void processKeyPress(const sf::Event &p_Event, const sf::Vector2f &p_MousePosition = sf::Vector2f(0, 0));

	/*!
		\brief Action any key releases.
		\param p_Event the player's input.
	*/
	void processKeyRelease(const sf::Event &p_Event); 

	/*!
		\brief Updates all entities in the game.
		\param p_DeltaTime the amount of time passed since the last update.
	*/
	void update(float p_DeltaTime);

	/*!
		\brief Draw method (from sf::Drawable).
		\param p_Target the canvas/window to draw to.
		\param p_States the state[s] of the OpenGL context.
	*/
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const;

	bool isRunning();  //!< Return whether the game is running, or not.

	/*!
		\brief Sets whether the game is running, or not.
		\param p_RunningState true if the game should be/is running, false if the game needs to be closed.
	*/
	void setRunningState(bool p_RunningState);
};