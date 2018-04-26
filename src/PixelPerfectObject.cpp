#include "PixelPerfectObject.h"

PixelPerfectObject::PixelPerfectObject() {
	m_Image.loadFromFile("./assets/Textures/Default.bmp");
	
}

PixelPerfectObject::PixelPerfectObject(const sf::Vector2f &p_Position, const sf::Image &p_Image) 
	: m_Image(p_Image) {
	
	m_Shape.setOrigin((float)(m_Image.getSize().x / 2), (float)(m_Image.getSize().y / 2));
	m_Shape.setPosition(p_Position);
}

PixelPerfectObject::PixelPerfectObject(const sf::Vector2f &p_Position, const sf::Texture &p_Texture) {
	m_Image = p_Texture.copyToImage();
}

PixelPerfectObject::PixelPerfectObject(const sf::Vector2f &p_Position, const std::string &p_FileLocation) {
	if (!m_Image.loadFromFile(p_FileLocation))
		m_Image.loadFromFile("./assets/Textures/Default.bmp");

	m_Shape.setOrigin((float)(m_Image.getSize().x / 2), (float)(m_Image.getSize().y / 2));
	m_Shape.setPosition(p_Position);
}

PixelPerfectObject::~PixelPerfectObject() {

}

void PixelPerfectObject::dealWithBounds(sf::Vector2f &p_Position) {
	if (p_Position.x >= m_Image.getSize().x)
		p_Position.x = (float)m_Image.getSize().x - 1;
	else if (p_Position.x <= 0)
		p_Position.x = 0.0f;

	if (p_Position.y >= m_Image.getSize().y)
		p_Position.y = (float)m_Image.getSize().y - 1;
	else if (p_Position.y <= 0)
		p_Position.y = 0.0f;
}

void PixelPerfectObject::removePixel(sf::Vector2f p_Position) {
	dealWithBounds(p_Position);
	m_Image.setPixel((unsigned int)p_Position.x, (unsigned int)p_Position.y, sf::Color::Transparent);
}

sf::Color PixelPerfectObject::getPixel(sf::Vector2f p_Position) {
	dealWithBounds(p_Position);
	return m_Image.getPixel(static_cast<unsigned int>(p_Position.x), static_cast<unsigned int>(p_Position.y));
}

void PixelPerfectObject::setPixel(sf::Vector2f p_Position, const sf::Color &p_Colour) {
	dealWithBounds(p_Position);
	m_Image.setPixel((unsigned int)p_Position.x, (unsigned int)p_Position.y, p_Colour);
}

sf::Image &PixelPerfectObject::getImage() {
	return m_Image;
}

void PixelPerfectObject::setImage(const sf::Image &p_Image) {
	m_Image = p_Image;
}

void PixelPerfectObject::setImage(const std::string &p_FileLocation) {
	if (!m_Image.loadFromFile(p_FileLocation))
		m_Image.loadFromFile("./assets/Textures/Default.bmp");
}