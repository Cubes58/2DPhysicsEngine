/**
@file UserInterface.h
@brief Manages the player's HUD.
*/
#pragma once

#include <string>

#include <SFML/Graphics.hpp>

#include "Team.h"

/*! \class UserInterface
	\brief Manages the player's HUD.
*/

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

	/*!
		\brief Initialize rectangle objects.
		\param p_RectangleShape the rectangle shape, being initialized.
		\param p_Position the starting position of the rectangle shape.
		\param p_Colour the colour of the rectangle shape.
		\param p_Size the size of the rectangle.
	*/
	void initialiseRectangle(sf::RectangleShape &p_RectangleShape, const sf::Vector2f &p_Position, 
		const sf::Color &p_Colour, const sf::Vector2f &p_Size = sf::Vector2f(50.0f, 15.0f));

	/*!
		\brief Initialize text objects.
		\param p_Text text object, displayed on the window.
		\param p_StringText the information that'll be displayed.
		\param p_Position the position of the text.
		\param p_Colour the colour of the text.
		\param p_Font the font of the text.
		\param p_CharacterSize the size of the text.
	*/
	void initialiseText(sf::Text &p_Text, const std::string &p_StringText, const sf::Vector2f &p_Position, 
		const sf::Color p_Colour, sf::Font &p_Font, unsigned int p_CharacterSize = 14); 
public:
	/*!
		\brief Constructor.
		\param p_WindowSize size of the window.
		\param p_GameOver state of the game.
	*/
	UserInterface(const sf::Vector2f &p_WindowSize, bool &p_GameOver);
	~UserInterface(); //!< Destructor.

	/*!
		\brief Set the string of a text object.
		\param p_Text text object that's displayed on the window.
		\param p_StringText the information the text object will show.
	*/
	void setText(sf::Text &p_Text, const std::string &p_StringText);

	/*!
		\brief Update the game's user interface (HUD).
		\param p_RedPlayerHealth the health of the red player.
		\param p_BluePlayerHealth the health of the blue player.
	*/
	void update(float p_RedPlayerHealth, float p_BluePlayerHealth);

	/*!
		\brief Draw method (from Drawable).
		\param p_Target the canvas/window to draw to.
		\param p_States the state of the draw method.
	*/
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const;

	/*!
		\brief Process key event[s].
		\param p_Event the event that invoked this method.
	*/
	void processKeyPress(const sf::Event &p_Event);
	
	/*!
		\brief Set the team that's won the game.
		\param p_TeamWinner the team that won, the game.
	*/
	void setWinner(const Team &p_TeamWinner);

	sf::Text &getRedPlayerScore(); //!< Returns the red player's score text.
	sf::Text &getRedPlayerHealth(); //!< Returns the red player's health text.
	sf::Text &getBluePlayerScore(); //!< Returns the blue player's score text.
	sf::Text &getBluePlayerHealth(); //!< Returns the blue player's health text.
};