#pragma once

#include <SFML\Graphics.hpp>

class DynamicPixel : public sf::Drawable {
private:
	sf::RectangleShape m_PixelRectangle;

	sf::Vector2f m_Position;
	sf::Vector2f m_PreviousPosition;

	sf::Vector2f m_Velocity;
	sf::Vector2f m_Acceleration;
	static const sf::Vector2f m_AccelerationFormula;

	sf::Color m_Colour;
	float m_Friction;				//Where do I use these????
	float m_Restitution;
public:
	DynamicPixel(sf::Vector2f p_Position);
	DynamicPixel(sf::Vector2f p_Position, sf::Vector2f p_Velocity);
	DynamicPixel(sf::Vector2f p_Position, sf::Vector2f p_Velocity, sf::Vector2f p_Acceleration);
	DynamicPixel(sf::Vector2f p_Position, sf::Vector2f p_Velocity, sf::Vector2f p_Acceleration, sf::Color p_Colour);

	void update(sf::Time p_DeltaTime);
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const;

	// Accessor methods.
	sf::Vector2f getPosition();
	void setPosition(const sf::Vector2f &p_Position);

	sf::Vector2f getPreviousPosition();
	
	sf::Vector2f getVelocity();
	void setVelocity(const sf::Vector2f &p_Velocity);

	sf::Vector2f getAcceleration();
	void setAcceleration(const sf::Vector2f &p_Accleration);

	sf::Color getColour();
	void setColour(const sf::Color &p_Colour);

	float getFriction();
	void setFriction(float p_Friction);

	float getRestitution();
	void setRestitution(float p_Restitution);
};