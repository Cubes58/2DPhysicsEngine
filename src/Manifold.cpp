#include "Manifold.h"

Manifold::Manifold(Terrain *p_Terrain, Soldier *p_Soldier, std::vector<sf::Vector2f> &p_CollisionNormals, float p_DeltaTime) {
	for (const auto &i : p_CollisionNormals) {
		m_FinalCollisionNormal.x += i.x;
		m_FinalCollisionNormal.y += i.y;
	}
	m_FinalCollisionNormal.x /= p_CollisionNormals.size();
	m_FinalCollisionNormal.y /= p_CollisionNormals.size();

	m_FinalCollisionNormal = (p_Soldier->getPosition() - m_FinalCollisionNormal);

	float newTime = -p_DeltaTime;
	p_Soldier->update(newTime);

	// Check if he collides.
	if (m_FinalCollisionNormal.x < 1 && m_FinalCollisionNormal.x > -1) {
		m_FinalCollisionNormal.x = 0;
		p_Soldier->setVelocity(sf::Vector2f(0, p_Soldier->getVelocity().y));
	}

	if (m_FinalCollisionNormal.y < 1 && m_FinalCollisionNormal.y > -1) {
		m_FinalCollisionNormal.y = 0;
		p_Soldier->setVelocity(sf::Vector2f(p_Soldier->getVelocity().x, 0));
	}

	// Apply impulse to FinalCollisionNormal.
	p_Soldier->applyImpulse(sf::Vector2f(m_FinalCollisionNormal.x, m_FinalCollisionNormal.y));
}

Manifold::Manifold(Terrain *p_Terrain, Bomb *p_Bomb, std::vector<sf::Vector2f> &p_CollisionNormals, float p_DeltaTime) {
	// Nothing to do here!
}

Manifold::Manifold(Soldier *p_SoldierOne, Soldier *p_SoldierTwo, std::vector<sf::Vector2f> &p_CollisionNormals, float p_DeltaTime) {
	for (const auto &i : p_CollisionNormals) {
		m_FinalCollisionNormal.x += i.x;
		m_FinalCollisionNormal.y += i.y;
	}
	m_FinalCollisionNormal.x /= p_CollisionNormals.size();
	m_FinalCollisionNormal.y /= p_CollisionNormals.size();

	// Apply impulse to FinalCollisionNormal.
	m_FinalCollisionNormal = (p_SoldierOne->getPosition() - m_FinalCollisionNormal);

	// Move the soldiers, so they aren't hitting each other.
	float newTime = -p_DeltaTime;
	p_SoldierOne->update(newTime);
	p_SoldierTwo->update(newTime);
}

Manifold::Manifold(Soldier *p_Soldier, Bomb *p_Bomb, std::vector<sf::Vector2f> &p_CollisionNormals, float p_DeltaTime) {

}

Manifold::Manifold(Terrain *p_Terrain, DynamicPixel *p_DynamicPixel, std::vector<sf::Vector2f> &p_CollisionNormals, float p_DeltaTime) {
	for (const auto &i : p_CollisionNormals) {
		m_FinalCollisionNormal.x += i.x;
		m_FinalCollisionNormal.y += i.y;
	}
	m_FinalCollisionNormal.x /= p_CollisionNormals.size();
	m_FinalCollisionNormal.y /= p_CollisionNormals.size();

	m_FinalCollisionNormal = (p_DynamicPixel->getPosition() - m_FinalCollisionNormal);

	float newTime = -p_DeltaTime;
	p_DynamicPixel->update(newTime);
	p_DynamicPixel->update(newTime);
}

Manifold::Manifold(Soldier *p_Soldier, StaticBlock *p_StaticBlock, std::vector<sf::Vector2f> &p_CollisionNormals, float p_DeltaTime) {
	for (const auto &i : p_CollisionNormals) {
		m_FinalCollisionNormal.x += i.x;
		m_FinalCollisionNormal.y += i.y;
	}
	m_FinalCollisionNormal.x /= p_CollisionNormals.size();
	m_FinalCollisionNormal.y /= p_CollisionNormals.size();

	// Apply impulse to FinalCollisionNormal.
	m_FinalCollisionNormal = (p_Soldier->getPosition() - m_FinalCollisionNormal);

	// Move the soldiers, so they aren't hitting each other.
	float newTime = -p_DeltaTime;
	p_Soldier->update(newTime);
	p_Soldier->update(newTime);
}