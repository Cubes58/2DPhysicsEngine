#include "Manifold.h"

Manifold::Manifold(Terrain *p_Terrain, Soldier *p_Soldier, std::vector<sf::Vector2f> p_CollisionNormals) {

}

Manifold::Manifold(Terrain *p_Terrain, Rocket *p_Rocket, std::vector<sf::Vector2f> p_CollisionNormals) {

}

Manifold::Manifold(Soldier *p_SoldierOne, Soldier *p_SoldierTwo, std::vector<sf::Vector2f> p_CollisionNormals) {

}

Manifold::Manifold(Soldier *p_Soldier, Rocket *p_Rocket, std::vector<sf::Vector2f> p_CollisionNormals) {

}

void Manifold::ResolveCollision() {
	// Seperate the objects
	// set velocity to 0
}