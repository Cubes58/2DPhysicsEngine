#pragma once

#include <SFML\Graphics.hpp>

class GameObject : public sf::Drawable {
protected:
	sf::Vector2f m_Position;
	sf::Vector2f m_Size;

	GameObject() = default;
	GameObject(const sf::Vector2f &p_Position, const sf::Vector2f &p_Size) : m_Position(p_Position), m_Size(p_Size) {

	}
public:
	virtual void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const = 0;

	sf::Vector2f getPosition() {
		return m_Position;
	}
	void setPosition(sf::Vector2f p_Position) {
		m_Position = p_Position;
	}

	sf::Vector2f getSize() {
		return m_Size;
	}
	void setSize(sf::Vector2f p_Size) {
		m_Size = p_Size;
	}
};