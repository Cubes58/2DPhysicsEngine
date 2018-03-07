#pragma once

#include <SFML\Graphics.hpp>

class Soldier : public sf::Drawable {
private:
	sf::RectangleShape m_SoldierRectangle;

	sf::Vector2f m_PreviousPosition;
	sf::Vector2f m_Position;

	sf::Vector2f m_Velocity;
	sf::Vector2f m_Acceleration;
	static const sf::Vector2f m_AccelerationFormula;

	sf::Color m_Colour;
public:
	Soldier();
	~Soldier();

	void update(sf::Time p_DeltaTime);
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const;

	sf::Vector2f getPosition();
	sf::Vector2f getSize();
};