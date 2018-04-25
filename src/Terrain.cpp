#include "Terrain.h"

Terrain::Terrain() {
	loadTerrain("./assets/scenes/MapOne.png");	// Has to be an 8 bit image.
	TextureManager::instance().loadTexture("Terrain", m_StaticTerrain);
}

Terrain::~Terrain() {

}

sf::Color Terrain::getPixel(const sf::Vector2f &p_Position) {
	return m_StaticTerrain.getPixel(static_cast<unsigned int>(p_Position.x), static_cast<unsigned int>(p_Position.y));
}

void Terrain::removePixel(const sf::Vector2f &p_Position) {
	m_StaticTerrain.setPixel(p_Position.x, p_Position.y, sf::Color::Transparent);
}

void Terrain::addPixel(const sf::Vector2f &p_Position, const sf::Color &p_Colour) {
	m_StaticTerrain.setPixel(p_Position.x, p_Position.y, p_Colour);
}

void Terrain::setDynamicPixel(const sf::Vector2f &p_Position, const sf::Color &p_Colour) {
	// Remove pixel from the static image, update the texture, with the "new" image, add a dynamic pixel.
	m_DynamicPixelManager.createSinglePixel(p_Position, p_Colour);

	removePixel(p_Position);
}

void Terrain::setDynamicPixelCluster(const sf::Vector2f &p_Position, const sf::Color &p_Colour, int p_NumberOfPixels) {
	m_DynamicPixelManager.createClusterOfPixels(p_Position, p_Colour, p_NumberOfPixels);
}

sf::Vector2f Terrain::calculateCollisionNormal(const sf::Vector2f &p_Position) const {
	static const int s_kiSearchBoxSize = 3;
	
	sf::Vector2f average(0, 0);
	int counter(0);
	for (int i = -s_kiSearchBoxSize; i <= s_kiSearchBoxSize; i++) {
		for (int j = -s_kiSearchBoxSize; j <= s_kiSearchBoxSize; j++) {
			if (m_StaticTerrain.getPixel(p_Position.x + i, p_Position.y + j) != sf::Color::Transparent) {
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
	TextureManager::instance().updateTexture("Terrain", m_StaticTerrain);

	m_DynamicPixelManager.update(p_DeltaTime);
}

void Terrain::draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const {
	static sf::Sprite sprite;
	sprite.setTexture(*TextureManager::instance().getTexture("Terrain"));
	
	p_Target.draw(sprite);
	p_Target.draw(m_DynamicPixelManager);
}

bool Terrain::loadTerrain(const std::string &p_FileLocation) {
	if (m_StaticTerrain.loadFromFile(p_FileLocation))
		return true;

	m_StaticTerrain.loadFromFile("./assets/scenes/Default");
	return false;
}

sf::Image &Terrain::getTerrain() {
	return m_StaticTerrain;
}

sf::Vector2f Terrain::getSize() {
	return static_cast<sf::Vector2f>(m_StaticTerrain.getSize());
}

void Terrain::DestroyTerrain(sf::CircleShape &p_CircleShape) {
	// Spawn some dynamic pixels, before the pixel[s] are removed, so we know the colour.
	setDynamicPixelCluster(p_CircleShape.getPosition(), getPixel(p_CircleShape.getPosition()));

	sf::RenderTexture renderTexture; 
	renderTexture.create(m_StaticTerrain.getSize().x, m_StaticTerrain.getSize().y);
	renderTexture.clear(sf::Color::Transparent);

	sf::Sprite terrainTexture;
	terrainTexture.setTexture(*TextureManager::instance().getTexture("Terrain"));

	renderTexture.draw(terrainTexture);
	p_CircleShape.setFillColor(sf::Color::Magenta);	// Be careful not to use Magenta for terrain pixels.
	renderTexture.draw(p_CircleShape);

	sf::Texture newTexture(renderTexture.getTexture());
	m_StaticTerrain = newTexture.copyToImage();
	m_StaticTerrain.flipVertically();	// Have to flip the pixels back 'cause the renderTexture flips them.
	
	for (int i = p_CircleShape.getPosition().x - p_CircleShape.getRadius(); i < p_CircleShape.getPosition().x + p_CircleShape.getRadius(); i++) {
		for (int j = p_CircleShape.getPosition().y - p_CircleShape.getRadius(); j < p_CircleShape.getPosition().y + p_CircleShape.getRadius(); j++) {
			if (getPixel(sf::Vector2f(i, j)) == sf::Color::Magenta)
				removePixel(sf::Vector2f(i, j));
		}
	}
}

void Terrain::DestroyTerrain(const sf::Vector2f &p_Position, float size) {
	// Spawn some dynamic pixels, before the pixel[s] are removed, so we know the colour.
	//setDynamicPixelCluster(p_Position, getPixel(p_Position));
	setDynamicPixelCluster(p_Position, sf::Color::Green);

	sf::RenderTexture renderTexture;
	renderTexture.create(m_StaticTerrain.getSize().x, m_StaticTerrain.getSize().y);
	renderTexture.clear(sf::Color::Transparent);

	sf::Sprite terrainTexture;
	terrainTexture.setTexture(*TextureManager::instance().getTexture("Terrain"));
	
	sf::CircleShape circle;
	circle.setOrigin(sf::Vector2f(size / 2, size / 2));
	circle.setRadius(size / 2);
	circle.setPosition(p_Position);
	circle.setFillColor(sf::Color::Magenta);

	renderTexture.draw(terrainTexture);
	renderTexture.draw(circle);

	sf::Texture newTexture(renderTexture.getTexture());
	m_StaticTerrain = newTexture.copyToImage();
	m_StaticTerrain.flipVertically();	// Have to flip the pixels back because the renderTexture flips them.

	for (int i = circle.getPosition().x - circle.getRadius(); i < circle.getPosition().x + circle.getRadius(); i++) {
		for (int j = circle.getPosition().y - circle.getRadius(); j < circle.getPosition().y + circle.getRadius(); j++) {
			if ((i >= 0 && i < m_StaticTerrain.getSize().x) && (j >= 0 && j < m_StaticTerrain.getSize().y)) {
				if (getPixel(sf::Vector2f(i, j)) == sf::Color::Magenta)
					removePixel(sf::Vector2f(i, j));
			}
		}
	}
}