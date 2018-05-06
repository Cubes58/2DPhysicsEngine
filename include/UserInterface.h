/**
@file UserInterface.h
*/
#pragma once

#include <string>

#include <SFML/Graphics.hpp>

#include "Team.h"

class UserInterface : public sf::Drawable {
private:
	sf::Font m_Font; //!< Font used for the text.

	sf::Text m_RedPlayerScore; //!< Red player's score, text.
	sf::Text m_RedPlayerHealth; //!< Red player's health, text.
	sf::RectangleShape m_RedPlayerHealthBar; //!< Red player's health bar.
	sf::RectangleShape m_RedPlayerAreaBackground; //!< Red player's user interface background.

	sf::Text m_BluePlayerScore; //!< Blue player's score, text.
	sf::Text m_BluePlayerHealth; //!< Blue player's health, text.
	sf::RectangleShape m_BluePlayerHealthBar; //!< Blue player's health bar.
	sf::RectangleShape m_BluePlayerAreaBackground; //!< Blue player's user interface background.

	bool &m_GameOver; //!< Monitors to see when the game is over.
	sf::Text m_ExitTextInformatiom; //!< Exit button.
	sf::Text m_WinnerInformation; //!< Displays who has won.
	sf::RectangleShape m_GameOverBackground; //!< Game over background, displayed at the end of the game.
	Team m_Winner; //!< Player winner.

	void initialiseRectangle(sf::RectangleShape &p_RectangleShape, const sf::Vector2f &p_Position, 
		const sf::Color &p_Colour, const sf::Vector2f &p_Size = sf::Vector2f(50.0f, 15.0f)); //!< Initialise rectangle objects.

	void initialiseText(sf::Text &p_Text, const std::string &p_StringText, const sf::Vector2f &p_Position, 
		const sf::Color p_Colour, sf::Font &p_Font, unsigned int p_CharacterSize = 14); //!< Initialise text objects.
public:
	UserInterface(const sf::Vector2f &p_WindowSize, bool &p_GameOver); //!< Constructor.
	~UserInterface(); //!< Destructor.

	void setText(sf::Text &p_Text, const std::string &p_StringText); //!< Set the string of a text object.

	void update(float p_RedPlayerHealth, float p_BluePlayerHealth); //!< Update the game's user interface (HUD).
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const; //!< Draw method (from sf::Drawable).

	void processKeyPress(const sf::Event &p_Event); //!< Process key event[s].
	
	void setWinner(const Team &p_TeamWinner);

	sf::Text &getRedPlayerScore(); //!< Return the red player's score text.
	sf::Text &getRedPlayerHealth(); //!< Return the red player's health text.
	sf::Text &getBluePlayerScore(); //!< Return the blue player's score text.
	sf::Text &getBluePlayerHealth(); //!< Return the blue player's health text.
};