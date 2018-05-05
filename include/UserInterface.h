#pragma once

#include <string>

#include <SFML/Graphics.hpp>

class UserInterface : public sf::Drawable {
private:
	sf::Font m_Font;

	sf::Text m_RedPlayerScore;
	sf::Text m_RedPlayerHealth;
	sf::RectangleShape m_RedPlayerHealthBar;
	sf::RectangleShape m_RedPlayerAreaBackground;

	sf::Text m_BluePlayerScore;
	sf::Text m_BluePlayerHealth;
	sf::RectangleShape m_BluePlayerHealthBar;
	sf::RectangleShape m_BluePlayerAreaBackground;

	void initialiseRectangle(sf::RectangleShape &p_RectangleShape, const sf::Vector2f &p_Position, 
		const sf::Color &p_Colour, const sf::Vector2f &p_Size = sf::Vector2f(50.0f, 15.0f));

	void initialiseText(sf::Text &p_Text, const std::string &p_StringText, const sf::Vector2f &p_Position, const sf::Color p_Colour, sf::Font &p_Font, unsigned int p_CharacterSize = 14);
public:
	/*
	* Complete constructor for the UserInterface.
	@param[in] p_Rectangle
	*/

	UserInterface(const sf::Vector2f &p_WindowSize);
	~UserInterface();

	void setText(sf::Text &p_Text, const std::string &p_StringText);

	void update(float p_RedPlayerHealth, float p_BluePlayerHealth);
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const;

	sf::Text &getRedPlayerScore();
	sf::Text &getRedPlayerHealth();
	sf::Text &getBluePlayerScore();
	sf::Text &getBluePlayerHealth();
};