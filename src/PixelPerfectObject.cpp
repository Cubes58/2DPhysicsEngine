#include "PixelPerfectObject.h"

PixelPerfectObject::PixelPerfectObject() {

}

PixelPerfectObject::PixelPerfectObject(const sf::Image &p_Image) 
	: m_Image(p_Image) {
	
}

PixelPerfectObject::PixelPerfectObject(const std::string &p_FileLocation) {
	if (!m_Image.loadFromFile(p_FileLocation))
		m_Image.loadFromFile("./assets/Textures/Default");
}

PixelPerfectObject::~PixelPerfectObject() {

}

void PixelPerfectObject::setImage(const sf::Image &p_Image) {
	m_Image = p_Image;
}

void PixelPerfectObject::setImage(const std::string &p_FileLocation) {
	if (!m_Image.loadFromFile(p_FileLocation))
		m_Image.loadFromFile("./assets/Textures/Default");
}

void PixelPerfectObject::dealWithinBounds(sf::Vector2f &p_Position) {
	if (p_Position.x >= m_Image.getSize().x)
		p_Position.x = m_Image.getSize().x;
	else if (p_Position.x <= 0)
		p_Position.x = 0;

	if (p_Position.y >= m_Image.getSize().y)
		p_Position.y = m_Image.getSize().y;
	else if (p_Position.y <= 0)
		p_Position.y = 0;

}

void PixelPerfectObject::removePixel(sf::Vector2f p_Position) {
	dealWithinBounds(p_Position);
	m_Image.setPixel(p_Position.x, p_Position.y, sf::Color::Transparent);
}

sf::Color PixelPerfectObject::getPixel(sf::Vector2f p_Position) {
	dealWithinBounds(p_Position);
	return m_Image.getPixel(static_cast<unsigned int>(p_Position.x), static_cast<unsigned int>(p_Position.y));
}

void PixelPerfectObject::setPixel(sf::Vector2f p_Position, const sf::Color &p_Colour) {
	dealWithinBounds(p_Position);
	m_Image.setPixel(p_Position.x, p_Position.y, p_Colour);
}

sf::Vector2f PixelPerfectObject::getSize() {
	return static_cast<sf::Vector2f>(m_Image.getSize());
}