#include "Manifold.h"

Manifold::Manifold(Terrain *p_Terrain, Soldier *p_Soldier, std::vector<sf::Vector2f> p_CollisionNormals) {
	for (auto i : p_CollisionNormals) {
		m_FinalCollisionNormal += i;
	}
	m_FinalCollisionNormal.x /= p_CollisionNormals.size();
	m_FinalCollisionNormal.y /= p_CollisionNormals.size();

	sf::Vector2f projection = sf::Vector2f(p_Soldier->getVelocity().x, p_Soldier->getVelocity().y);

	sf::Vector2f velocity = p_Soldier->getVelocity();
	velocity.x -= m_FinalCollisionNormal.x * projection.x;
	velocity.y -= m_FinalCollisionNormal.y * projection.y;

	//p_Soldier->setVelocity(velocity);

	p_Soldier->applyImpulse(sf::Vector2f(5.0f, -150.0f));
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