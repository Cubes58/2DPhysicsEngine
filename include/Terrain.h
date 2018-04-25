#pragma once

#include <vector>

#include <SFML\Graphics.hpp>

#include "GameObject.h"
#include "PixelPerfectObject.h"
#include "TextureManager.h"
#include "DynamicPixelManager.h"
#include "DynamicPixel.h"

class Terrain : public GameObject, public PixelPerfectObject {
private:
	DynamicPixelManager m_DynamicPixelManager;
public:
	Terrain(const sf::Vector2f &p_Position, const sf::Vector2f &p_Size);
	~Terrain();

	void setDynamicPixel(const sf::Vector2f &p_Position, const sf::Color &p_Colour);
	void setDynamicPixelCluster(const sf::Vector2f &p_Position, const sf::Color &p_Colour, int p_NumberOfPixels = 20);

	sf::Vector2f calculateCollisionNormal(const sf::Vector2f &p_Position) const;
	
	void update(float p_DeltaTime);	
	void draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const;

	void destroyTerrain(sf::CircleShape &p_CircleShape);
	void destroyTerrain(const sf::Vector2f &p_Position, float size = 80);
};