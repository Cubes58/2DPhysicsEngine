#pragma once

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>

class PixelPerfectObject {
protected:
	sf::Image m_Image;
	sf::RectangleShape m_Shape;
	
	PixelPerfectObject();
	PixelPerfectObject(const sf::Vector2f &p_Position, const sf::Image &p_Image);
	PixelPerfectObject(const sf::Vector2f &p_Position, const sf::Texture &p_Texture);
	PixelPerfectObject(const sf::Vector2f &p_Position, const std::string &p_FileLocation);
	~PixelPerfectObject();

	void dealWithBounds(sf::Vector2f &p_Position);
public:
	void removePixel(sf::Vector2f p_Position);
	sf::Color getPixel(sf::Vector2f p_Position);
	void setPixel(sf::Vector2f p_Position, const sf::Color &p_Colour);

	sf::Image &getImage();
	void setImage(const sf::Image &p_Image);
	void setImage(const std::string &p_FileLocation);
};