#include "Terrain.h"

// Profile code.
// Testing report.
// Doxygen report.
// Video of the game - compress, video over telling you what's going on, could go on YouTube etc... (2.5 minutes)
// Showing the mechanics and features. (YouTube [best] - Send the link OR OneDive (Add link to upload))

Terrain::Terrain(const sf::Vector2f &p_Position, const sf::Vector2f &p_Size) 
	: GameObject(p_Position, p_Size), PixelPerfectObject(p_Position, "./assets/scenes/MapOne.png") {

	TextureManager::instance().loadTexture("Terrain", m_Image);
	m_RenderTexture.create(m_Image.getSize().x, m_Image.getSize().y);

	m_Shape.setSize(m_Size);
	m_Shape.setOrigin(p_Size.x / 2, p_Size.y / 2);
	m_Shape.setPosition(p_Position);
	m_Shape.setTexture(TextureManager::instance().getTexture("Terrain"));
}

Terrain::~Terrain() {

}

void Terrain::setDynamicPixel(const sf::Vector2f &p_Position, const sf::Color &p_Colour) {
	// Remove pixel from the static image, update the texture, with the "new" image, add a dynamic pixel.
	m_DynamicPixelManager.createSinglePixel(p_Position, p_Colour);

	removePixel(p_Position);
}

void Terrain::setDynamicPixelCluster(const sf::Vector2f &p_Position, const std::vector<sf::Color> &p_Colours) {
	m_DynamicPixelManager.createClusterOfPixels(p_Position, p_Colours);
}

sf::Vector2f Terrain::calculateCollisionNormal(const sf::Vector2f &p_Position) const {
	static const int s_kiSearchBoxSize = 3;
	
	sf::Vector2f average(0, 0);
	int counter(0);
	for (int i = -s_kiSearchBoxSize; i <= s_kiSearchBoxSize; i++) {
		for (int j = -s_kiSearchBoxSize; j <= s_kiSearchBoxSize; j++) {
			if (m_Image.getPixel(p_Position.x + i, p_Position.y + j) != sf::Color::Transparent) {
				average.x -= i;
				average.y -= j;
				counter++;
			}			
		}
	}
	average = average / (float)counter;
	float length = sqrt(average.x * average.x + average.y * average.y);

	return average / length;
}

void Terrain::update(float p_DeltaTime) {
	TextureManager::instance().updateTexture("Terrain", m_Image);
	m_Shape.setTexture(TextureManager::instance().getTexture("Terrain"));

	m_DynamicPixelManager.update(p_DeltaTime);
}

void Terrain::draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const {	
	p_Target.draw(m_Shape);
	p_Target.draw(m_DynamicPixelManager);
}

void Terrain::destroyTerrain(sf::Shape *p_Shape) {
	static sf::Sprite terrainTexture;
	terrainTexture.setTexture(*TextureManager::instance().getTexture("Terrain"));

	// Make sure the shape's colour is Transparent.
	p_Shape->setFillColor(sf::Color::Transparent);

	m_RenderTexture.clear(sf::Color::Transparent);
	m_RenderTexture.draw(terrainTexture);
	m_RenderTexture.draw(*p_Shape, sf::BlendMultiply);
	m_RenderTexture.display();

	sf::Texture newTexture(m_RenderTexture.getTexture());
	m_Image = newTexture.copyToImage();
	TextureManager::instance().updateTexture("Terrain", m_Image);
}

void Terrain::destroyTerrain(const sf::Vector2f &p_Position, const std::vector<sf::Color> &p_PixelColours, float size) {
	static sf::Sprite terrainTexture;
	terrainTexture.setTexture(*TextureManager::instance().getTexture("Terrain"));
	
	sf::CircleShape circle;
	circle.setOrigin(sf::Vector2f(size / 2, size / 2));
	circle.setRadius(size / 2);
	circle.setPosition(p_Position);
	circle.setFillColor(sf::Color::Transparent);

	m_RenderTexture.clear(sf::Color::Transparent);
	m_RenderTexture.draw(terrainTexture);
	m_RenderTexture.draw(circle, sf::BlendMultiply);
	m_RenderTexture.display();

	sf::Texture newTexture(m_RenderTexture.getTexture());
	m_Image = newTexture.copyToImage();
	TextureManager::instance().updateTexture("Terrain", m_Image);

	// MOVE THIS TO THE GAME.cpp
	for (const auto &i : p_PixelColours)
		setDynamicPixel(p_Position, i);
}