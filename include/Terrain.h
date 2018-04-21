#pragma once

#include <vector>

#include <SFML\Graphics.hpp>
//#include <SFML\Graphics\Image.hpp>

#include "TextureManager.h"
#include "DynamicPixelManager.h"
#include "DynamicPixel.h"

class Terrain : public sf::Drawable {
private:
	sf::Image m_StaticTerrain;
	DynamicPixelManager m_DynamicPixelManager;
public:
	Terrain();
	~Terrain();

	sf::Color getPixel(const sf::Vector2f &p_Position);
	void removePixel(const sf::Vector2f &p_Position);
	void addPixel(const sf::Vector2f &p_Position, const sf::Color &p_Colour);
	void setDynamicPixel(const sf::Vector2f &p_Position, const sf::Color &p_Colour);
	void setDynamicPixelCluster(const sf::Vector2f &p_Position, const sf::Color &p_Colour, int p_NumberOfPixels = 20);

	sf::Vector2f calculateCollisionNormal(const sf::Vector2f &p_Position) const;
	
	void update(float p_DeltaTime);	
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const;

	bool loadTerrain(const std::string &p_FileLocation);
	sf::Image &getTerrain();

	sf::Vector2f getSize();

	void DestroyTerrain(sf::CircleShape &p_CircleShape);
	void DestroyTerrain(const sf::Vector2f &p_Position, float size = 60);
};