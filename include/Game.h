#pragma once

#include <SFML\Graphics.hpp>

#include "Terrain.h"
#include "Soldier.h"
#include "Rocket.h"

#include "Manifold.h"

class Game : public sf::Drawable {
private:
	Terrain m_Terrain;
	DynamicPixel m_DynamicPixelTest;

	Soldier m_Soldier;

	bool m_bIsRunning;
public:
	Game();
	~Game();

	void processKeyPress(sf::Keyboard::Key p_Key);
	void processKeyRelease(sf::Keyboard::Key p_Key);

	void update(sf::Time p_DeltaTime);
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const;

	bool isRunning();
	void setRunningState(bool p_bRunningState);


	bool Collision(Terrain t, Soldier s, std::vector<sf::Vector2f> &p_CollisionPoints);
};