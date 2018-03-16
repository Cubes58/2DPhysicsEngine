#pragma once

#include "Terrain.h"
#include "Soldier.h"
#include "Rocket.h"
#include "Collision.h"

class Manifold {
private:
	Collision m_Collision;

	sf::Vector2f m_FinalCollisionNormal;			// Average all the collision normals. 

	std::vector<sf::Vector2f> m_CollisionNormals;	// Calculate the collision normal for said position.
public:
	/* Checks where they've collided, then react accordingly - Move the objects apart. */
	Manifold(Terrain *p_Terrain, Soldier *p_Soldier, std::vector<sf::Vector2f> &p_CollisionNormals, float p_DeltaTime);
	Manifold(Terrain *p_Terrain, Rocket *p_Rocket, std::vector<sf::Vector2f> p_CollisionNormals);

	Manifold(Soldier *p_SoldierOne, Soldier *p_SoldierTwo, std::vector<sf::Vector2f> p_CollisionNormals);
	Manifold(Soldier *p_Soldier, Rocket *p_Rocket, std::vector<sf::Vector2f> p_CollisionNormals);
};

// Double Dispatch.