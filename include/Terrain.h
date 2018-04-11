#pragma once

#include <vector>

#include <SFML\Graphics.hpp>
//#include <SFML\Graphics\Image.hpp>

#include "TextureManager.h"
#include "DynamicPixel.h"

class Terrain : public sf::Drawable {
private:
	sf::Image m_StaticTerrain;
	std::vector<DynamicPixel> m_DynamicPixels;
public:
	Terrain();

	sf::Color getPixel(const sf::Vector2f &p_Position);
	void removePixel(const sf::Vector2f &p_Position);
	void addPixel(const sf::Vector2f &p_Position, const sf::Color &p_Colour);
	void setDynamicPixel(const sf::Vector2f &p_Position, const sf::Color &p_Colour);

	sf::Vector2f calculateCollisionNormal(const sf::Vector2f &p_Position) const;
	
	void update(float p_DeltaTime);			// Maybe add a bool that checks if the image/texture has been updated. 'Cause updating the image is expensive.
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const;

	bool loadTerrain(const std::string &p_FileLocation);
	sf::Image &getTerrain();

	//sf::Vector2f pos;
	//sf::Vector2f normal;

	sf::Vector2f getSize();
	void DestroyTerrain();
};