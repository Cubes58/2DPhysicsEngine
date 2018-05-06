/**
@file Manifold.h
*/
#pragma once

#include "Terrain.h"
#include "Soldier.h"
#include "Bomb.h"
#include "Collision.h"
#include "DynamicPixel.h"

class Manifold {
private:
	Collision m_Collision; //!< Collision object, to check whether the objects are still colliding or not.

	sf::Vector2f m_FinalCollisionNormal; //!<  Average of all the collision normals - final/calculated collision normal. 
	std::vector<sf::Vector2f> m_CollisionNormals; //!< Vector of collision normals.
public:
	/* Checks where they've collided, then reacts accordingly - Moves the objects apart. */
	Manifold(Terrain *p_Terrain, Soldier *p_Soldier, std::vector<sf::Vector2f> &p_CollisionNormals, float p_DeltaTime);  //!< Constructor.

	Manifold(Soldier *p_SoldierOne, Soldier *p_SoldierTwo, std::vector<sf::Vector2f> &p_CollisionNormals, float p_DeltaTime); //!< Constructor.
	Manifold(Soldier *p_Soldier, Bomb *p_Bomb, std::vector<sf::Vector2f> &p_CollisionNormals, float p_Penetration); //!< Constructor.

	Manifold(Terrain *p_Terrain, DynamicPixel *p_DynamicPixel, std::vector<sf::Vector2f> &p_CollisionNormals, float p_DeltaTime); //!< Constructor.
};