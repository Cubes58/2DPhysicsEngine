/**
@file PixelPerfectObject.h
@brief A base class, which has the properties, and behavior necessary to make an object pixel perfect.
*/
#pragma once

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>

/*! \class PixelPerfectObject
	\brief A base class, which has the properties, and behavior necessary to make an object pixel perfect.
*/

class PixelPerfectObject {
protected:
	sf::Image m_Image; //!< Image used for the pixel perfect collision.
	sf::RectangleShape m_Shape; //!< sf::RectangleShape, to draw the image (object).
	
	PixelPerfectObject(); //!< Constructor.

	/*!
		\brief Constructor.
		\param p_Position starting position of the pixel perfect object.
		\param p_Image the image of the pixel perfect object.
	*/
	PixelPerfectObject(const sf::Vector2f &p_Position, const sf::Image &p_Image); 

	/*!
		\brief Constructor.
		\param p_Position starting position of the pixel perfect object.
		\param p_Texture the texture of the pixel perfect object.
	*/
	PixelPerfectObject(const sf::Vector2f &p_Position, const sf::Texture &p_Texture);

	/*!
		\brief Constructor.
		\param p_Position starting position of the pixel perfect object.
		\param p_FileLocation the location of the image.
	*/
	PixelPerfectObject(const sf::Vector2f &p_Position, const std::string &p_FileLocation);
	~PixelPerfectObject(); //!< Destructor.

	/*!
		\brief Deals with out of bound positions, to make sure they're in bounds (of the image - m_Image).
		\param p_Position position to check whether its within the pixel range of the pixel perfect object.
	*/
	void dealWithBounds(sf::Vector2f &p_Position);
public:
	/*!
		\brief Removes a pixel, from the image.
		\param p_Position the position of the pixel to remove.
	*/
	void removePixel(sf::Vector2f p_Position);  


	/*!
		\brief Returns the colour of a pixel, from the image.
		\param p_Position position of the pixel to get its colour.
		\return returns the colour of the pixel.
	*/
	sf::Color getPixel(sf::Vector2f p_Position);


	/*!
		\brief Sets the colour of a pixel, on the image.
		\param p_Position position of the pixel to set.
		\param p_Colour the colour to set the pixel.
	*/
	void setPixel(sf::Vector2f p_Position, const sf::Color &p_Colour);

	sf::Image &getImage(); //!< Returns the image.

	/*!
		\brief Sets the image, using an image.
		\param p_Image set the image being used, to the image passed in.
	*/
	void setImage(const sf::Image &p_Image);

	/*!
		\brief Sets the image, using a file location.
		\param p_FileLocation set the image to the one stored at the file location.
	*/
	void setImage(const std::string &p_FileLocation);
};