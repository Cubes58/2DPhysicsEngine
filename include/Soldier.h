#pragma once

#include "DynamicObject.h"
#include "MouseClickObserver.h"

// TEMP TEST
#include <iostream>

class Soldier : public DynamicObject, public MouseClickObserver {
private:
	sf::RectangleShape m_Shape;

	sf::Color m_Colour;
public:
	Soldier(sf::Vector2f p_Position, sf::Vector2f p_Size, sf::Vector2f p_Velocity, sf::Vector2f p_Acceleration);
	~Soldier();

	void update(MouseClickEvent p_State);
	void update(float p_DeltaTime);
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const;
};