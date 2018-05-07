/**
@file DynamicPixelManager.h
*/
#pragma once

#include <vector>
#include <memory>
#include <algorithm>

#include "DynamicPixel.h"
#include "Randomiser.h"

/*! \class DynamicPixelManager.h
\brief Manages Dynamic Pixels.
*/

class DynamicPixelManager : public sf::Drawable {
private:
	std::vector<std::shared_ptr<DynamicPixel>> m_DynamicPixels; //!< A vector of DynamicPixel objects.

	void cleanUpPixels(); //!< Clears every pixel, to clear the memory.
public:
	DynamicPixelManager(); //!< Constructor.
	~DynamicPixelManager(); //!< Destructor. 

	void update(float p_DeltaTime); //!< Updates every DynamicPixel, stored in the vector of pixels (m_DynamicPixels).
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const; //!< Draw method (sf::Drawable).

	void createClusterOfPixels(const sf::Vector2f &p_Position, std::vector<sf::Color> &p_Colours, 
		const sf::Vector2f &p_RandomXPossibleValue = sf::Vector2f(-50, 50), const sf::Vector2f &p_RandomYPossibleValue = sf::Vector2f(-50, 50)); //!< Creates a cluster of DynamicPixels.
	void createSinglePixel(const sf::Vector2f &p_Position, sf::Color &p_colour, 
		const sf::Vector2f &p_RandomXPossibleValue = sf::Vector2f(-50, 50), const sf::Vector2f &p_RandomYPossibleValue = sf::Vector2f(-50, 50)); //!< Creates a DynamicPixel.

	std::vector<std::shared_ptr<DynamicPixel>> &getDynamicPixels(); //!< Returns a vector of shared pointers pointing to DynamicPixels.
};