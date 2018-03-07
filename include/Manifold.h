#pragma once

#include "Terrain.h"
#include "Soldier.h"
#include "Rocket.h"

class Manifold {
private:
	void ResolveCollision();						//Push the object away, in the direction of the fnalCollisiongNormal.
	
	sf::Vector2f m_FinalCollisionNormal;			//Average all the collision normals 
public:
	std::vector<sf::Vector2f> m_PixelPositions;		//Set once a collision has occurred. Push_back each pixel position, as they occur.
	std::vector<sf::Vector2f> m_CollisionNormals;	//Calculate the collision normal for said position.

	/* Checks where they've collided, then react accordingly - Move the objects apart. */
	Manifold(Terrain *p_Terrain, Soldier *p_Soldier);
	Manifold(Terrain *p_Terrain, Rocket *p_Rocket);

	Manifold(Soldier *p_SoldierOne, Soldier *p_SoldierTwo);
	Manifold(Soldier *p_Soldier, Rocket *p_Rocket);
};