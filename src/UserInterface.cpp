#include "UserInterface.h"

UserInterface::UserInterface(const sf::Vector2f &p_WindowSize) {
	m_Font.loadFromFile("./assets/fonts/Arial.ttf");

	initialiseRectangle(m_RedPlayerHealthBar, sf::Vector2f(p_WindowSize.x - ((p_WindowSize.x / 10.0f) * 9.5f), p_WindowSize.y / 12.0f), sf::Color::Red);
	initialiseRectangle(m_RedPlayerAreaBackground, sf::Vector2f(p_WindowSize.x - ((p_WindowSize.x / 10.0f) * 9.7f), (p_WindowSize.y / 12.0f) / 4.2f),
		sf::Color::Black, sf::Vector2f(p_WindowSize.x / 10.0f, (p_WindowSize.y / 12.0f) * 1.2f));

	initialiseRectangle(m_BluePlayerHealthBar, sf::Vector2f((p_WindowSize.x - (p_WindowSize.x / 10.0f)), p_WindowSize.y / 12.0f), sf::Color::Blue);
	initialiseRectangle(m_BluePlayerAreaBackground, sf::Vector2f(p_WindowSize.x - (p_WindowSize.x / 10.0f * 1.2), (p_WindowSize.y / 12.0f) / 4.2f),
		sf::Color::Black, sf::Vector2f(p_WindowSize.x / 10.0f, (p_WindowSize.y / 12.0f) * 1.2f));

	initialiseText(m_RedPlayerScore, "Score: ", sf::Vector2f(p_WindowSize.x - ((p_WindowSize.x / 10.0f) * 9.5f), (p_WindowSize.y / 12.0f) / 3.5f), sf::Color::Red, m_Font);
	initialiseText(m_RedPlayerHealth, "Health: ", sf::Vector2f(p_WindowSize.x - ((p_WindowSize.x / 10.0f) * 9.5f), (p_WindowSize.y / 12.0f) / 1.4f), sf::Color::Red, m_Font);

	initialiseText(m_BluePlayerScore, "Score: ", sf::Vector2f((p_WindowSize.x - (p_WindowSize.x / 10.0f)), (p_WindowSize.y / 12.0f) / 3.5f), sf::Color::Blue, m_Font);
	initialiseText(m_BluePlayerHealth, "Health: ", sf::Vector2f((p_WindowSize.x - (p_WindowSize.x / 10.0f)), (p_WindowSize.y / 12.0f) / 1.4f), sf::Color::Blue, m_Font);
}

UserInterface::~UserInterface() {

}

void UserInterface::initialiseRectangle(sf::RectangleShape &p_RectangleShape,
	const sf::Vector2f &p_Position, const sf::Color &p_Colour, const sf::Vector2f &p_Size) {
	p_RectangleShape.setPosition(p_Position);
	p_RectangleShape.setSize(p_Size);
	p_RectangleShape.setFillColor(p_Colour);
	p_RectangleShape.setOutlineThickness(-1);
	p_RectangleShape.setOutlineColor(sf::Color::Black);
}

void UserInterface::initialiseText(sf::Text &p_Text, const std::string &p_StringText, const sf::Vector2f &p_Position, const sf::Color p_Colour, 
	sf::Font &p_Font, unsigned int p_CharacterSize) {
	p_Text.setPosition(p_Position);
	p_Text.setFillColor(p_Colour);
	p_Text.setCharacterSize(p_CharacterSize);
	p_Text.setFont(p_Font);
	p_Text.setString(p_StringText);
}

void UserInterface::setText(sf::Text &p_Text, const std::string &p_StringText) {
	p_Text.setString(p_StringText);
}

void UserInterface::update(float p_RedPlayerHealth, float p_BluePlayerHealth) {
	m_RedPlayerHealthBar.setSize(sf::Vector2f(p_RedPlayerHealth * 0.75f, 15.0f));

	m_BluePlayerHealthBar.setSize(sf::Vector2f(p_BluePlayerHealth * 0.75f, 15.0f));
}

void UserInterface::draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const {
	p_Target.draw(m_RedPlayerAreaBackground, p_States);
	p_Target.draw(m_RedPlayerScore, p_States);
	p_Target.draw(m_RedPlayerHealth, p_States);
	p_Target.draw(m_RedPlayerHealthBar, p_States);

	p_Target.draw(m_BluePlayerAreaBackground, p_States);
	p_Target.draw(m_BluePlayerScore, p_States);
	p_Target.draw(m_BluePlayerHealth, p_States);
	p_Target.draw(m_BluePlayerHealthBar, p_States);
}

sf::Text &UserInterface::getRedPlayerScore() {
	return m_RedPlayerScore;
}

sf::Text &UserInterface::getRedPlayerHealth() {
	return m_RedPlayerHealth;
}

sf::Text &UserInterface::getBluePlayerScore() {
	return m_BluePlayerScore;
}

sf::Text &UserInterface::getBluePlayerHealth() {
	return m_BluePlayerHealth;
}