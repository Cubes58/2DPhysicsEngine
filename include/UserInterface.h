#pragma once

#include <SFML/Graphics.hpp>

class UserInterface {
private:
	sf::Text m_RedPlayerScore;
	sf::Text m_RedPlayerHealth;
	sf::RectangleShape m_RedPlayerHealthBar;
	sf::RectangleShape m_RedPlayerAreaBackground;

	sf::Text m_BluePlayerScore;
	sf::Text m_BluePlayerHealth;
	sf::RectangleShape m_BluePlayerHealthBar;
	sf::RectangleShape m_BluePlayerAreaBackground;
public:
	UserInterface();
	~UserInterface();

	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const;
};