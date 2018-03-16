#pragma once

#include "Soldier.h"
#include "Rocket.h"
#include "Terrain.h"

class Collision {
private:

public:
	bool operator()(Terrain &p_Terrain, Soldier &p_Soldier, std::vector<sf::Vector2f> &p_CollisionPoints) {
		bool bCollision(false);

		sf::Vector2f startPoint = sf::Vector2f(p_Soldier.getPosition().x - (p_Soldier.getSize().x / 2), p_Soldier.getPosition().y - (p_Soldier.getSize().y / 2));
		sf::Vector2f endPoint = sf::Vector2f(p_Soldier.getPosition().x + (p_Soldier.getSize().x / 2), p_Soldier.getPosition().y + (p_Soldier.getSize().y / 2));

		/* Have to check that i and j are larger than 0, and that they're smaller than the height/width. */

		for (int i = startPoint.x; (i > 0 && i < p_Terrain.getSize().x) && i <= endPoint.x; i++) {
			for (int j = startPoint.y; (j > 0 && j < p_Terrain.getSize().y) && j <= endPoint.y; j++) {
				if (p_Terrain.getPixel(sf::Vector2f(i, j)) != sf::Color::Transparent) {
					p_CollisionPoints.push_back(sf::Vector2f(i, j));

					bCollision = true;
				}
			}
		}

		return bCollision;
	}

	bool operator()(Terrain &p_Terrain, Rocket &p_Rocket, std::vector<sf::Vector2f> &p_CollisionPoints) {
		bool bCollision(false);

		sf::Vector2f startPoint = sf::Vector2f(p_Rocket.getPosition().x - (p_Rocket.getSize().x / 2), p_Rocket.getPosition().y - (p_Rocket.getSize().y / 2));
		sf::Vector2f endPoint = sf::Vector2f(p_Rocket.getPosition().x + (p_Rocket.getSize().x / 2), p_Rocket.getPosition().y + (p_Rocket.getSize().y / 2));

		/* Have to check that i and j are larger than 0, and that they're smaller than the height/width. */

		for (int i = startPoint.x; (i > 0 && i < p_Terrain.getSize().x) && i <= endPoint.x; i++) {
			for (int j = startPoint.y; (j > 0 && j < p_Terrain.getSize().y) && j <= endPoint.y; j++) {
				if (p_Terrain.getPixel(sf::Vector2f(i, j)) != sf::Color::Transparent) {
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

		/* Have to check that i and j are larger than 0, and that they're smaller than the height/width. */

		/*
		for (int i = startPoint.x; (i > 0 && i < p_SoldierTwo.getSize().x) && i <= endPoint.x; i++) {
			for (int j = startPoint.y; (j > 0 && j < p_SoldierTwo.getSize().y) && j <= endPoint.y; j++) {
				if (p_SoldierTwo.getPixel(sf::Vector2f(i, j)) != sf::Color::Transparent) {
					p_CollisionPoints.push_back(sf::Vector2f(i, j));

					bCollision = true; //go fuck yourself 
				}
			}
		}*/
		
		return bCollision;
	}

	bool operator()(Soldier &p_Soldier, Rocket &p_Rocket, std::vector<sf::Vector2f> &p_CollisionPoints) {
		bool bCollision(false);

		

		return bCollision;
	}
};