#pragma once

#include <SFML/Graphics.hpp>

class PixelPerfectObject {
protected:
	sf::Image m_Image;
	
	PixelPerfectObject();
	PixelPerfectObject(const sf::Image &p_Image);
	PixelPerfectObject(const std::string &p_FileLocation);
	~PixelPerfectObject();

	void setImage(const sf::Image &p_Image);
	void setImage(const std::string &p_FileLocation);

	void dealWithinBounds(sf::Vector2f &p_Position);
public:
	void removePixel(sf::Vector2f p_Position);
	sf::Color getPixel(sf::Vector2f p_Position);
	void setPixel(sf::Vector2f p_Position, const sf::Color &p_Colour);
};