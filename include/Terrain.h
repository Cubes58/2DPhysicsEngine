/**
@file Terrain.h
@brief Game's terrain.
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
	/*!
		\brief Constructor.
		\param p_Position center position of the terrain.
		\param p_Size size of the terrain.
	*/
	Terrain(const sf::Vector2f &p_Position, const sf::Vector2f &p_Size);
	~Terrain(); //!< Destructor.

	/*!
		\brief Calculates a collision normal, given a position.
		\param p_Position position of the collision.
	*/
	sf::Vector2f calculateCollisionNormal(const sf::Vector2f &p_Position) const;
	
	/*!
		\brief Updates the terrain.
		\param p_DeletaTime time passed, since the last update.
	*/
	void update(float p_DeltaTime);

	/*!
		\brief Draw method (from GameObject/sf::drawable).
		\param p_Target renderTarget to draw to.
		\param p_States states of the openGL context.
	*/
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const;

	/*!
		\brief Destroys the terrain, given an sf::Shape.
		\param p_Shape shape type to remove from the terrain.
	*/
	void destroyTerrain(sf::Shape *p_Shape);

	/*!
		\brief Destroys the terrain given a position, and an optional size.
		\param p_Position position of where to remove the terrain.
		\param p_Size size of the circle to remove, from the terrain.
	*/
	void destroyTerrain(const sf::Vector2f &p_Position, float p_Size = 80);
};