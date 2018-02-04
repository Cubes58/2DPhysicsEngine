#pragma once

#define _USE_MATH_DEFINES
#include <cmath>

#include <SFML\System\Vector2.hpp>

class Manifold {
private:

public:
	//Object *m_ObjectOne;
	//Object *m_ObjectTwo;
	float m_fPenetration;
	sf::Vector2f m_CollisionNormal;
};

struct AABB {
	sf::Vector2f m_Min;
	sf::Vector2f m_Max;
};

struct Circle {
	float m_Radius;
	sf::Vector2f m_Position;
};

bool AABBvsAABB(AABB p_AABBOne, AABB p_AABBTwo) {
	//Exit if there's an axis that seperates them.
	if (p_AABBOne.m_Max.x < p_AABBTwo.m_Min.x || p_AABBOne.m_Min.x > p_AABBTwo.m_Max.x)
		return false;
	if (p_AABBOne.m_Max.y < p_AABBTwo.m_Min.y || p_AABBOne.m_Min.y > p_AABBTwo.m_Max.y)
		return false;

	return true;
}

float distance(sf::Vector2f a, sf::Vector2f b) {
	return (float)sqrt((int)(a.x - b.x)^2 + (int)(a.y - b.y)^2);
}

bool circlevsCircleUnoptimised(Circle a, Circle b) {
	float r = a.m_Radius + b.m_Radius;
	return r < distance(a.m_Position, b.m_Position);
}

bool circlevsCircleOptimised(Circle a, Circle b) {
	float r = a.m_Radius + b.m_Radius;
	r *= r;
	return r < ((int)(a.m_Position.x + b.m_Position.x)^2) + ((int)(a.m_Position.y + b.m_Position.y)^2);
}