/**
@file Game.h
*/
#pragma once

#include <memory>

#include <SFML\Graphics.hpp>

#include "TextureManager.h"
#include "Collision.h"
#include "Manifold.h"
#include "UserInterface.h"
#include "Background.h"
#include "Terrain.h"
#include "DynamicPixelManager.h"
#include "Soldier.h"
#include "Bomb.h"

class Game : public sf::Drawable {
private:
	sf::Vector2f m_Gravity; //!< World's gravity.

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

	void processKeyPress(const sf::Event &p_Event, const sf::Vector2f &p_MousePosition = sf::Vector2f(0, 0)); //!< Action any key presses.
	void processKeyRelease(const sf::Event &p_Event); //!< Action any key releases.

	void update(float p_DeltaTime); //!< Updates all entities in the game.
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const;  //!< Draw method (from sf::Drawable).

	bool isRunning();  //!< Return whether the game is running, or not.
	void setRunningState(bool p_bRunningState); //!< Sets whether the game is running, or not.
};