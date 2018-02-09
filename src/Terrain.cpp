#include "Terrain.h"

Terrain::Terrain() : m_StaticTerrain(TextureManager::instance().getTerrain()) {
	TextureManager::instance().createTexture("Terrain", m_StaticTerrain);
	pos = sf::Vector2f(714.f, 386.f);
	normal = calculateCollisionNormal(pos.x, pos.y);
	normal = normal * 50.f;
}

sf::Color Terrain::getPixel(unsigned int p_XPosition, unsigned int p_YPosition) {
	return m_StaticTerrain.getPixel(p_XPosition, p_YPosition);
}

void Terrain::removePixel(unsigned int p_XPosition, unsigned int p_YPosition) {
	m_StaticTerrain.setPixel(p_XPosition, p_YPosition, sf::Color::Transparent);
}

void Terrain::addPixel(unsigned int p_XPosition, unsigned int p_YPosition, sf::Color p_Colour) {
	m_StaticTerrain.setPixel(p_XPosition, p_YPosition, p_Colour);
}

void Terrain::setDynamicPixel(unsigned int p_XPosition, unsigned int p_YPosition) {
	//Remove pixel from the static image, update the texture, with the "new" image, add a dynamic pixel.
}

sf::Vector2f Terrain::calculateCollisionNormal(unsigned int p_XPosition, unsigned int p_YPosition) {
	sf::Vector2f average(0,0);
	int counter = 0;
	for (int i = -3; i <= 3; i++) {
		for (int j = -3; j <= 3; j++) {
			if (m_StaticTerrain.getPixel(i+ p_XPosition, p_YPosition + j) != sf::Color::Transparent) {
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

void Terrain::update() {
	TextureManager::instance().updateTexture("Terrain", m_StaticTerrain);
}

void Terrain::draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const {
	sf::Sprite p;
	p.setTexture(*TextureManager::instance().getTexture("Terrain"));
	
	p_Target.draw(p);

	sf::VertexArray line(sf::PrimitiveType::Lines, 2);
	line[0] = sf::Vertex(pos, sf::Color::Magenta);
	line[1] = sf::Vertex(pos + sf::Vector2f(normal.x, normal.y), sf::Color::Magenta);

	p_Target.draw(line);
}