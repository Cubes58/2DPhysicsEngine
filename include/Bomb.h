#pragma once

#include "DynamicObject.h"
#include "PixelPerfectObject.h"
#include "TextureManager.h"

class Bomb : public DynamicObject, public PixelPerfectObject {
private:
	sf::RectangleShape m_Shape;

	bool m_HitSomething = false;
public:
	Bomb(const sf::Vector2f &p_Position, const sf::Vector2f &p_Size, const sf::Vector2f &p_Velocity, const sf::Vector2f &p_Acceleration = sf::Vector2f(0, 98.1));
	~Bomb();

	void update(float p_DeltaTime);
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const;

	bool getHitSomething();
	void setHitSomething(bool p_HitSomething);
};