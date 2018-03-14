#include "Terrain.h"

Terrain::Terrain() {
	loadTerrain("./assets/scenes/Temp.png");
	TextureManager::instance().loadTexture("Terrain", m_StaticTerrain);

	/*
	pos = sf::Vector2f(714.f, 386.f);
	normal = calculateCollisionNormal(pos);
	normal.x = normal.x * 50;
	normal.y = normal.y * 50;
	*/
}

sf::Color Terrain::getPixel(const sf::Vector2f &p_Position) {
	return m_StaticTerrain.getPixel(p_Position.x, p_Position.y);
}

void Terrain::removePixel(const sf::Vector2f &p_Position) {
	m_StaticTerrain.setPixel(p_Position.x, p_Position.y, sf::Color::Transparent);
}

void Terrain::addPixel(const sf::Vector2f &p_Position, const sf::Color &p_Colour) {
	m_StaticTerrain.setPixel(p_Position.x, p_Position.y, p_Colour);
}

void Terrain::setDynamicPixel(const sf::Vector2f &p_Position, const sf::Color &p_Colour) {
	//Remove pixel from the static image, update the texture, with the "new" image, add a dynamic pixel.
	DynamicPixel temp(p_Position, sf::Vector2f(20, 10), sf::Vector2f(1, 2), p_Colour);
	m_DynamicPixels.push_back(temp);

	removePixel(p_Position);
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

	for (auto i = m_DynamicPixels.begin(); i != m_DynamicPixels.end(); ++i) {
		i->update(p_DeltaTime);

		//Change this to the position of the pixel - if it's say 100 pixels away from its original position.
		if (i->getVelocity().x < 0 && i->getVelocity().y < 0) {
			//Delete it
			m_DynamicPixels.erase(i);
		}
	}
}

void Terrain::draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const {
	static sf::Sprite sprite;
	sprite.setTexture(*TextureManager::instance().getTexture("Terrain"));
	
	p_Target.draw(sprite);
	
	/*
	sf::Vector2f pos;
	sf::Vector2f normal;
	pos = sf::Vector2f(714.f, 386.f);
	//TEST: Fake - pos = sf::Vector2f(20.0f, 440.f);
	normal = calculateCollisionNormal(pos);
	normal = normal * 50.f;
	*/
	
	/*
	sf::VertexArray line(sf::PrimitiveType::Lines, 2);
	line[0] = sf::Vertex(pos, sf::Color::Magenta);
	line[1] = sf::Vertex(pos + sf::Vector2f(normal.x, normal.y), sf::Color::Magenta);

	p_Target.draw(line);
	*/
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