#pragma once

#include <SFML\Graphics.hpp>

#include "Collision.h"
#include "Manifold.h"

#include "Terrain.h"
#include "Soldier.h"
#include "Bomb.h"


class Game : public sf::Drawable {
private:
	Collision m_Collision;
	Terrain m_Terrain;

	Soldier m_Soldier;

	bool m_bIsRunning;
public:
	Game();
	~Game();

	void processKeyPress(const sf::Event &p_Event, const sf::Vector2f &p_MousePosition = sf::Vector2f(0, 0));
	void processKeyRelease(sf::Event p_Event);

	void update(float p_DeltaTime);
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const;

	bool isRunning();
	void setRunningState(bool p_bRunningState);
};