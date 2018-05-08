/**
@file DynamicPixelManager.h
@brief Manages Dynamic Pixels.
*/
#pragma once

#include <vector>
#include <memory>
#include <algorithm>

#include "DynamicPixel.h"
#include "Randomiser.h"

/*! \class DynamicPixelManager
	\brief Manages Dynamic Pixels.
*/

class DynamicPixelManager : public sf::Drawable {
private:
	std::vector<std::shared_ptr<DynamicPixel>> m_DynamicPixels; //!< A vector of DynamicPixel objects.

	void cleanUpPixels(); //!< Clears every pixel, to clear the memory.
public:
	DynamicPixelManager(); //!< Constructor.
	~DynamicPixelManager(); //!< Destructor. 

	/*!
		\brief Updates every DynamicPixel, stored in the vector of pixels (m_DynamicPixels).
		\param p_DeltaTime the amount of time passed since this was last called.
	*/
	void update(float p_DeltaTime);

	/*!
		\brief Draw method (Drawable).
		\param p_Target the canvas/window to draw to.
		\param p_States the state[s] of the OpenGL context.
	*/
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const;

	/*!
		\brief Creates a cluster of DynamicPixels.
		\param p_Position the starting position of the dynamic pixels.
		\param p_Colours the (different) colours of the dynamic pixels.
		\param p_RandomXPossibleValue the minimum possible x and y speeds, for the dynamic pixel.
		\param p_RandomYPossibleValue the maximum possible x and y speeds, for the dynamic pixel.
	*/
	void createClusterOfPixels(const sf::Vector2f &p_Position, std::vector<sf::Color> &p_Colours, 
		const sf::Vector2f &p_RandomXPossibleValue = sf::Vector2f(-50, 50), const sf::Vector2f &p_RandomYPossibleValue = sf::Vector2f(-50, 50)); 
	
	/*!
		\brief Creates a DynamicPixel.
		\param p_Position the starting position of the dynamic pixel.
		\param p_Colour the colour of the dynamic pixel.
		\param p_RandomXPossibleValue the minimum possible x and y speeds, for the dynamic pixel.
		\param p_RandomYPossibleValue the maximum possible x and y speeds, for the dynamic pixel.
	*/
	void createSinglePixel(const sf::Vector2f &p_Position, sf::Color &p_Colour, 
		const sf::Vector2f &p_RandomXPossibleValue = sf::Vector2f(-50, 50), const sf::Vector2f &p_RandomYPossibleValue = sf::Vector2f(-50, 50)); 

	std::vector<std::shared_ptr<DynamicPixel>> &getDynamicPixels(); //!< Returns a vector of shared pointers pointing to DynamicPixels.
};