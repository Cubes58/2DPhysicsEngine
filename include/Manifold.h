/**
@file Manifold.h
@brief A class that resolves the collision, these tend to be generated when needed.
*/
#pragma once

#include "Terrain.h"
#include "Soldier.h"
#include "Bomb.h"
#include "Collision.h"
#include "DynamicPixel.h"

/*! \class Manifold
	\brief A class that resolves the collision, these tend to be generated when needed.
*/

class Manifold {
private:
	Collision m_Collision; //!< Collision object, to check whether the objects are still colliding or not.

	sf::Vector2f m_FinalCollisionNormal; //!<  Average of all the collision normals - final/calculated collision normal. 
	std::vector<sf::Vector2f> m_CollisionNormals; //!< Vector of collision normals.
public:
	/* Checks where they've collided, then reacts accordingly - Moves the objects apart. */

	/*!
		\brief Constructor.
		\param p_Terrain the terrain to check the collision with.
		\param p_Soldier the soldier to check the collision with.
		\param p_CollisionNormals the collision normals generated from by the collision class.
		\param p_DeltaTime the amount of time passed, when the collision occurred.
	*/
	Manifold(Terrain *p_Terrain, Soldier *p_Soldier, std::vector<sf::Vector2f> &p_CollisionNormals, float p_DeltaTime);

	/*!
		\brief Constructor.
		\param p_SoldierOne the soldier to check the collision with.
		\param p_SoldierTwo the soldier to check the collision with.
		\param p_CollisionNormals the collision normals generated from by the collision class.
		\param p_DeltaTime the amount of time passed, when the collision occurred.
	*/
	Manifold(Soldier *p_SoldierOne, Soldier *p_SoldierTwo, std::vector<sf::Vector2f> &p_CollisionNormals, float p_DeltaTime);  

	/*!
		\brief Constructor.
		\param p_Soldier the soldier to check the collision with.
		\param p_Bomb the bomb object to check the collision with.
		\param p_CollisionNormals the collision normals generated from by the collision class.
		\param p_Penetration the distance the object is inside of the other object.
	*/
	Manifold(Soldier *p_Soldier, Bomb *p_Bomb, std::vector<sf::Vector2f> &p_CollisionNormals, float p_Penetration); 

	/*!
		\brief Constructor.
		\param p_Terrain the terrain to check the collision with.
		\param p_DynamicPixel the dynamic pixel to check the collision with.
		\param p_CollisionNormals the collision normals generated from by the collision class.
		\param p_DeltaTime the amount of time passed, when the collision occurred.	
	*/
	Manifold(Terrain *p_Terrain, DynamicPixel *p_DynamicPixel, std::vector<sf::Vector2f> &p_CollisionNormals, float p_DeltaTime); 
};