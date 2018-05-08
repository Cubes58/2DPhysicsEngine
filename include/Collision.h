/**
@file Collision.h
@brief Used to detect collisions between object. 
*/
#pragma once

#include <cmath>

#include "Soldier.h"
#include "Bomb.h"
#include "Terrain.h"
#include "DynamicPixel.h"

/*! \class Collision
	\brief Used to detect collisions between object.
*/

class Collision {
private:
	/*!
		\brief Check whether position is in bounds.
		\param p_Position the position to check whether its in bounds or not. 
		\param p_MaxSize the size of the boundary.
		\return true if p_Position is within the bounds, false otherwise.
	*/
	bool inBounds(const sf::Vector2f &p_Position, const sf::Vector2f &p_MaxSize) {
		if ((p_Position.x >= 0 && p_Position.x < p_MaxSize.x) && (p_Position.y >= 0 && p_Position.y < p_MaxSize.y))
			return true;

		return false;
	}
public:
	/*!
		\brief Functor, to detect a collision between the terrain and a soldier.
		\param p_Terrain the terrain object to check collisions with.
		\param p_Soldier the solider object to check collisions with.
		\param p_CollisionPoints the collision points that will be generated when the collision happens.
		\return bool returns true if a collision has happened, false otherwise.
	*/
	bool operator()(Terrain &p_Terrain, Soldier &p_Soldier, std::vector<sf::Vector2f> &p_CollisionPoints) {
		p_CollisionPoints.clear();
		bool bCollision(false);

		sf::Vector2f startPoint = sf::Vector2f(p_Soldier.getPosition().x - (p_Soldier.getSize().x / 2), p_Soldier.getPosition().y - (p_Soldier.getSize().y / 2));
		sf::Vector2f endPoint = sf::Vector2f(p_Soldier.getPosition().x + (p_Soldier.getSize().x / 2), p_Soldier.getPosition().y + (p_Soldier.getSize().y / 2));

		if(startPoint.x < 0) {
			startPoint.x = 0;
		}

		for (int i = (int)startPoint.x; (i >= 0 && i < p_Terrain.getSize().x) && i <= endPoint.x; i++) {
			for (int j = (int)startPoint.y; (j >= 0 && j < p_Terrain.getSize().y) && j <= endPoint.y; j++) {
				if (inBounds(sf::Vector2f((float)i, (float)j), p_Terrain.getSize()) && p_Terrain.getPixel(sf::Vector2f((float)i, (float)j)) != sf::Color::Transparent) {
					p_CollisionPoints.push_back(sf::Vector2f((float)i, (float)j));

					bCollision = true;
				}
			}
		}

		return bCollision;
	}

	/*!
		\brief Functor, to detect a collision between the terrain and a bomb.
		\param p_Terrain the terrain object to check collisions with.
		\param p_Bomb the bomb object to check collisions with.
		\param p_CollisionPoints the collision points that will be generated when the collision happens.
		\return bool returns true if a collision has happened, false otherwise.
	*/
	bool operator()(Terrain &p_Terrain, Bomb &p_Bomb, std::vector<sf::Vector2f> &p_CollisionPoints) {
		p_CollisionPoints.clear();
		bool bCollision(false);

		sf::Vector2f startPoint = sf::Vector2f(p_Bomb.getPosition().x - (p_Bomb.getSize().x / 2), p_Bomb.getPosition().y - (p_Bomb.getSize().y / 2));
		sf::Vector2f endPoint = sf::Vector2f(p_Bomb.getPosition().x + (p_Bomb.getSize().x / 2), p_Bomb.getPosition().y + (p_Bomb.getSize().y / 2));

		for (int i = (int)startPoint.x; (i >= 0 && i < p_Terrain.getSize().x) && i <= endPoint.x; i++) {
			for (int j = (int)startPoint.y; (j >= 0 && j < p_Terrain.getSize().y) && j <= endPoint.y; j++) {
				if (inBounds(sf::Vector2f((float)i, (float)j), p_Terrain.getSize()) && p_Terrain.getPixel(sf::Vector2f((float)i, (float)j)) != sf::Color::Transparent) {
					p_CollisionPoints.push_back(sf::Vector2f((float)i, (float)j));

					bCollision = true;
				}
			}
		}

		return bCollision;
	}

	/*!
		\brief Functor, to detect a collision between two soldiers.
		\param p_SoldierOne the solider object to check collisions with.
		\param p_SoldierTwo the solider object to check collisions with.
		\param p_CollisionPoints the collision points that will be generated when the collision happens.
		\return bool returns true if a collision has happened, false otherwise.
	*/
	bool operator()(Soldier &p_SoldierOne, Soldier &p_SoldierTwo, std::vector<sf::Vector2f> &p_CollisionPoints) {
		p_CollisionPoints.clear();
		bool bCollision(false);

		sf::Vector2f startPoint = sf::Vector2f(p_SoldierOne.getPosition().x - (p_SoldierOne.getSize().x / 2), p_SoldierOne.getPosition().y - (p_SoldierOne.getSize().y / 2));
		sf::Vector2f endPoint = sf::Vector2f(p_SoldierOne.getPosition().x + (p_SoldierOne.getSize().x / 2), p_SoldierOne.getPosition().y + (p_SoldierOne.getSize().y / 2));

		for (int i = (int)startPoint.x; (i > 0 && i < p_SoldierTwo.getSize().x) && i <= endPoint.x; i++) {
			for (int j = (int)startPoint.y; (j > 0 && j < p_SoldierTwo.getSize().y) && j <= endPoint.y; j++) {
				if (inBounds(sf::Vector2f((float)i, (float)j), p_SoldierTwo.getSize()) && p_SoldierTwo.getPixel(sf::Vector2f((float)i, (float)j)) != sf::Color::Transparent) {
					p_CollisionPoints.push_back(sf::Vector2f((float)i, (float)j));

					bCollision = true;
				}
			}
		}

		return bCollision;
	}

	/*!
		\brief Functor, to detect a collision between a soldier and a bomb (AABB).
		\param p_Soldier the solider object to check collisions with.
		\param p_Bomb the bomb object to check collisions with.
		\param p_Penetration how much the AABBs have overlapped.
		\param p_CollisionPoints the collision points that will be generated when the collision happens.
		\return bool returns true if a collision has happened, false otherwise.
	*/
	bool operator()(Soldier &p_Soldier, Bomb &p_Bomb, float &p_Penetration, std::vector<sf::Vector2f> &p_CollisionPoints) {
		p_CollisionPoints.clear();
		if (p_Soldier.getTeam() == p_Bomb.getTeam()) {
			return false;
		}

		sf::Vector2f difference = p_Soldier.getPosition() - p_Bomb.getPosition();

		float overlapX = (p_Soldier.getSize().x / 2) + (p_Bomb.getSize().x / 2) - fabs(difference.x);
		if (overlapX > 0) {
			float overlapY = (p_Soldier.getSize().y / 2) + (p_Bomb.getSize().y / 2) - fabs(difference.y);
			if (overlapY > 0) {
				// Identify axis of least penetration.
				if (overlapX < overlapY) {
					p_Penetration = overlapX;
					if (difference.x < 0)
						p_CollisionPoints.push_back(sf::Vector2f(-1, 0));
					else 
						p_CollisionPoints.push_back(sf::Vector2f(1, 0));
				}
				else {
					p_Penetration = overlapY;
					if (difference.y < 0)
						p_CollisionPoints.push_back(sf::Vector2f(0, -1));
					else
						p_CollisionPoints.push_back(sf::Vector2f(0, 1));
				}
				return true;
			}
		}

		return false;
	}

	/*!
		\brief Functor, to detect a collision between the terrain and a dynamic pixel.
		\param p_Terrain the terrain object to check collisions with.
		\param p_DynamicPixel the dynamic pixel to check collisions with.
		\param p_CollisionPoints the collision points that will be generated when the collision happens.
		\return bool returns true if a collision has happened, false otherwise.
	*/
	bool operator()(Terrain &p_Terrain, DynamicPixel &p_DynamicPixel, std::vector<sf::Vector2f> &p_CollisionPoints) {
		p_CollisionPoints.clear();
		bool bCollision(false);

		sf::Vector2f startPoint = sf::Vector2f(p_DynamicPixel.getPosition().x - (p_DynamicPixel.getSize().x / 2), p_DynamicPixel.getPosition().y - (p_DynamicPixel.getSize().y / 2));
		sf::Vector2f endPoint = sf::Vector2f(p_DynamicPixel.getPosition().x + (p_DynamicPixel.getSize().x / 2), p_DynamicPixel.getPosition().y + (p_DynamicPixel.getSize().y / 2));

		for (int i = (int)startPoint.x; (i > 0 && i < p_Terrain.getSize().x) && i <= endPoint.x; i++) {
			for (int j = (int)startPoint.y; (j > 0 && j < p_Terrain.getSize().y) && j <= endPoint.y; j++) {
				if (inBounds(sf::Vector2f((float)i, (float)j), p_Terrain.getSize()) && p_Terrain.getPixel(sf::Vector2f((float)i, (float)j)) != sf::Color::Transparent) {
					p_CollisionPoints.push_back(sf::Vector2f((float)i, (float)j));

					bCollision = true;
				}
			}
		}

		return bCollision;
	}
};