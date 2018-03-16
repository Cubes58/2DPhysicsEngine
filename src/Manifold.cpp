#include "Manifold.h"

Manifold::Manifold(Terrain *p_Terrain, Soldier *p_Soldier, std::vector<sf::Vector2f> &p_CollisionNormals, float p_DeltaTime) {
	
	for (auto i : p_CollisionNormals) {
		m_FinalCollisionNormal.x += i.x;
		m_FinalCollisionNormal.y += i.y;
	}
	m_FinalCollisionNormal.x /= p_CollisionNormals.size();
	m_FinalCollisionNormal.y /= p_CollisionNormals.size();

	float newTime = -p_DeltaTime / 2.0f;
	p_Soldier->update(newTime);
	p_Soldier->update(newTime);
	// Check if he collides.

	if (m_Collision(*p_Terrain, *p_Soldier, p_CollisionNormals)) {
		newTime /= 2.0f;
		p_Soldier->update(newTime);

		if (m_Collision(*p_Terrain, *p_Soldier, p_CollisionNormals)) {
			p_Soldier->update(newTime);
			newTime /= 2.0f;
			//p_Soldier->applyImpulse(sf::Vector2f(5.0f, -550.0f));
		}
		//p_Soldier->applyImpulse(sf::Vector2f(5.0f, -550.0f));
	}
}

Manifold::Manifold(Terrain *p_Terrain, Rocket *p_Rocket, std::vector<sf::Vector2f> p_CollisionNormals) {

}

Manifold::Manifold(Soldier *p_SoldierOne, Soldier *p_SoldierTwo, std::vector<sf::Vector2f> p_CollisionNormals) {

}

Manifold::Manifold(Soldier *p_Soldier, Rocket *p_Rocket, std::vector<sf::Vector2f> p_CollisionNormals) {

}