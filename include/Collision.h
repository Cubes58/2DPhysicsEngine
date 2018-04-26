#pragma once

#include "Soldier.h"
#include "Bomb.h"
#include "Terrain.h"

class Collision {
private:
	bool inBounds(const sf::Vector2f &p_Position, const sf::Vector2f &p_MaxSize) {
		if ((p_Position.x >= 0 && p_Position.x < p_MaxSize.x) && (p_Position.y >= 0 && p_Position.y < p_MaxSize.y))
			return true;

		return false;
	}
public:
	bool operator()(Terrain &p_Terrain, Soldier &p_Soldier, std::vector<sf::Vector2f> &p_CollisionPoints) {
		bool bCollision(false);

		sf::Vector2f startPoint = sf::Vector2f(p_Soldier.getPosition().x - (p_Soldier.getSize().x / 2), p_Soldier.getPosition().y - (p_Soldier.getSize().y / 2));
		sf::Vector2f endPoint = sf::Vector2f(p_Soldier.getPosition().x + (p_Soldier.getSize().x / 2), p_Soldier.getPosition().y + (p_Soldier.getSize().y / 2));

		for (int i = (int)startPoint.x; (i > 0 && i < p_Terrain.getSize().x) && i <= endPoint.x; i++) {
			for (int j = (int)startPoint.y; (j > 0 && j < p_Terrain.getSize().y) && j <= endPoint.y; j++) {
				if (inBounds(sf::Vector2f((float)i, (float)j), p_Terrain.getSize()) && p_Terrain.getPixel(sf::Vector2f((float)i, (float)j)) != sf::Color::Transparent) {
					p_CollisionPoints.push_back(sf::Vector2f(i, j));

					bCollision = true;
				}
			}
		}

		return bCollision;
	}

	bool operator()(Terrain &p_Terrain, Bomb &p_Bomb, std::vector<sf::Vector2f> &p_CollisionPoints) {
		bool bCollision(false);

		sf::Vector2f startPoint = sf::Vector2f(p_Bomb.getPosition().x - (p_Bomb.getSize().x / 2), p_Bomb.getPosition().y - (p_Bomb.getSize().y / 2));
		sf::Vector2f endPoint = sf::Vector2f(p_Bomb.getPosition().x + (p_Bomb.getSize().x / 2), p_Bomb.getPosition().y + (p_Bomb.getSize().y / 2));

		for (int i = startPoint.x; (i > 0 && i < p_Terrain.getSize().x) && i <= endPoint.x; i++) {
			for (int j = startPoint.y; (j > 0 && j < p_Terrain.getSize().y) && j <= endPoint.y; j++) {
				if (inBounds(sf::Vector2f(i, j), p_Terrain.getSize()) && p_Terrain.getPixel(sf::Vector2f(i, j)) != sf::Color::Transparent) {
					p_CollisionPoints.push_back(sf::Vector2f(i, j));

					bCollision = true;
				}
			}
		}

		return bCollision;
	}

	bool operator()(Soldier &p_SoldierOne, Soldier &p_SoldierTwo, std::vector<sf::Vector2f> &p_CollisionPoints) {
		bool bCollision(false);

		sf::Vector2f startPoint = sf::Vector2f(p_SoldierOne.getPosition().x - (p_SoldierOne.getSize().x / 2), p_SoldierOne.getPosition().y - (p_SoldierOne.getSize().y / 2));
		sf::Vector2f endPoint = sf::Vector2f(p_SoldierOne.getPosition().x + (p_SoldierOne.getSize().x / 2), p_SoldierOne.getPosition().y + (p_SoldierOne.getSize().y / 2));

		for (int i = startPoint.x; (i > 0 && i < p_SoldierTwo.getSize().x) && i <= endPoint.x; i++) {
			for (int j = startPoint.y; (j > 0 && j < p_SoldierTwo.getSize().y) && j <= endPoint.y; j++) {
				if (inBounds(sf::Vector2f(i, j), p_SoldierTwo.getSize()) && p_SoldierTwo.getPixel(sf::Vector2f(i, j)) != sf::Color::Transparent) {
					p_CollisionPoints.push_back(sf::Vector2f(i, j));

					bCollision = true;
				}
			}
		}
		
		return bCollision;
	}

	bool operator()(Soldier &p_Soldier, Bomb &p_Bomb, std::vector<sf::Vector2f> &p_CollisionPoints) {
		bool bCollision(false);
		
		sf::Vector2f startPoint = sf::Vector2f(p_Soldier.getPosition().x - (p_Soldier.getSize().x / 2), p_Soldier.getPosition().y - (p_Soldier.getSize().y / 2));
		sf::Vector2f endPoint = sf::Vector2f(p_Soldier.getPosition().x + (p_Soldier.getSize().x / 2), p_Soldier.getPosition().y + (p_Soldier.getSize().y / 2));
		
		for (int i = startPoint.x; (i > 0 && i < p_Bomb.getSize().x) && i <= endPoint.x; i++) {
			for (int j = startPoint.y; (j > 0 && j < p_Bomb.getSize().y) && j <= endPoint.y; j++) {
				if (inBounds(sf::Vector2f(i, j), p_Soldier.getSize()) && p_Bomb.getPixel(sf::Vector2f(i, j)) != sf::Color::Transparent) {
					p_CollisionPoints.push_back(sf::Vector2f(i, j));

					bCollision = true;
				}
			}
		}

		return bCollision;
	}
};