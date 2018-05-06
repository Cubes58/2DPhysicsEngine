/**
@file PixelPerfectObject.h
*/
#pragma once

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>

class PixelPerfectObject {
protected:
	sf::Image m_Image; //!< Image used for the pixel perfect collision.
	sf::RectangleShape m_Shape; //!< sf::RectangleShape, to draw the image (object).
	
	PixelPerfectObject(); //!< Constructor.
	PixelPerfectObject(const sf::Vector2f &p_Position, const sf::Image &p_Image); //!< Constructor.
	PixelPerfectObject(const sf::Vector2f &p_Position, const sf::Texture &p_Texture); //!< Constructor.
	PixelPerfectObject(const sf::Vector2f &p_Position, const std::string &p_FileLocation); //!< Constructor.
	~PixelPerfectObject(); //!< Destructor.

	void dealWithBounds(sf::Vector2f &p_Position); //!< Deals with out of bound positions, to make sure they're in bounds (of the image - m_Image).
public:
	void removePixel(sf::Vector2f p_Position); //!< Removes a pixel, from the image.
	sf::Color getPixel(sf::Vector2f p_Position); //!< Returns the colour of a pixel, from the image.
	void setPixel(sf::Vector2f p_Position, const sf::Color &p_Colour); //!< Sets the colour of a pixel, on the image.

	sf::Image &getImage(); //!< Returns the image.
	void setImage(const sf::Image &p_Image); //!< Sets the image, using an image.
	void setImage(const std::string &p_FileLocation); //!< Sets the image, using a file location.
};