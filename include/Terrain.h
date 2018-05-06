/**
@file Terrain.h
*/
#pragma once

#include <vector>

#include <SFML\Graphics.hpp>
#include <SFML\Graphics\BlendMode.hpp>

#include "GameObject.h"
#include "PixelPerfectObject.h"
#include "TextureManager.h"

class Terrain : public GameObject, public PixelPerfectObject {
private:
	sf::RenderTexture m_RenderTexture; //!< Draw terrain to, modify it, update texture to modified terrain.
public:
	Terrain(const sf::Vector2f &p_Position, const sf::Vector2f &p_Size); //!< Constructor.
	~Terrain(); //!< Destructor.

	sf::Vector2f calculateCollisionNormal(const sf::Vector2f &p_Position) const; //!< Calculates a collision normal, given a position.
	
	void update(float p_DeltaTime);	 //!< Updates the terrain.
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const; //!< Draw method (from GameObject/sf::drawable).

	void destroyTerrain(sf::Shape *p_Shape); //!< Destroys the terrain, given an sf::Shape.
	void destroyTerrain(const sf::Vector2f &p_Position, float size = 80); //!< Destroys the terrain given a position, and an optional size.
};