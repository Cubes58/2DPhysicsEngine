#pragma once

#include "DynamicObject.h"
#include "PixelPerfectObject.h"
#include "TextureManager.h"
#include "Team.h"

class Bomb : public DynamicObject, public PixelPerfectObject {
private:
	Team m_Team;
	float m_Damage;

	bool outOfBounds();
public:
	Bomb(const Team &p_Team, const sf::Vector2f &p_Position, const sf::Vector2f &p_Gravity, const sf::Vector2f &p_Size, const sf::Vector2f &p_Velocity, 
		const sf::Vector2f &p_Acceleration = sf::Vector2f(0.0f, 98.1f));
	~Bomb();

	void update(float p_DeltaTime);
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const;

	Team getTeam();
	float getDamage();
};