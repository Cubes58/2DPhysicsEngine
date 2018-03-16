#pragma once

#include <SFML\Graphics.hpp>

#include "Terrain.h"
#include "Soldier.h"
#include "Rocket.h"
#include "Collision.h"

#include "Manifold.h"

class Game : public sf::Drawable {
private:
	Terrain m_Terrain;
	DynamicPixel m_DynamicPixelTest;
	Collision m_Collision;

	Soldier m_Soldier;
	Rocket m_Rocket;

	bool m_bIsRunning;
public:
	Game();
	~Game();

	void processKeyPress(sf::Keyboard::Key p_Key);
	void processKeyRelease(sf::Keyboard::Key p_Key);

	void update(float p_DeltaTime);
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const;

	bool isRunning();
	void setRunningState(bool p_bRunningState);
};