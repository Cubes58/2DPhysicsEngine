#include "Background.h"

Background::Background(const sf::Vector2f &p_WindowSize) {
	m_Background.setOrigin(sf::Vector2f(p_WindowSize.x / 2, p_WindowSize.y / 2));
	m_Background.setPosition(sf::Vector2f(p_WindowSize.x / 2, p_WindowSize.y / 2));
	m_Background.setSize(p_WindowSize);
	m_Background.setTexture(TextureManager::instance().getTexture("Background"));

	m_TintColour = sf::Color(255, 255, 255, 120);

	m_BackgroundTint.setOrigin(sf::Vector2f(p_WindowSize.x / 2, p_WindowSize.y / 2));
	m_BackgroundTint.setPosition(sf::Vector2f(p_WindowSize.x / 2, p_WindowSize.y / 2));
	m_BackgroundTint.setSize(p_WindowSize);
	m_BackgroundTint.setFillColor(m_TintColour);
}

Background::~Background() {

}

void Background::draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const {
	p_Target.draw(m_Background, p_States);
	p_Target.draw(m_BackgroundTint, p_States);
}