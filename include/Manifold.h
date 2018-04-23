#pragma once

#include "Terrain.h"
#include "Soldier.h"
#include "Bomb.h"
#include "Collision.h"

class Manifold {
private:
	Collision m_Collision;

	sf::Vector2f m_FinalCollisionNormal;			// Average of all the collision normals. 
	std::vector<sf::Vector2f> m_CollisionNormals;	// Calculate the collision normal for said position.
public:
	/* Checks where they've collided, then reacts accordingly - Moves the objects apart. */
	Manifold(Terrain *p_Terrain, Soldier *p_Soldier, std::vector<sf::Vector2f> &p_CollisionNormals, float p_DeltaTime);
	Manifold(Terrain *p_Terrain, Bomb *p_Rocket, std::vector<sf::Vector2f> p_CollisionNormals, float p_DeltaTime);

	Manifold(Soldier *p_SoldierOne, Soldier *p_SoldierTwo, std::vector<sf::Vector2f> p_CollisionNormals, float p_DeltaTime);
	Manifold(Soldier *p_Soldier, Bomb *p_Rocket, std::vector<sf::Vector2f> p_CollisionNormals, float p_DeltaTime);
};