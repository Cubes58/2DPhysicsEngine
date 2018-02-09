#include "Terrain.h"

Terrain::Terrain() : m_StaticTerrain(TextureManager::instance().getTerrain()) {
	TextureManager::instance().createTexture("Terrain", m_StaticTerrain);
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

void Terrain::update() {
	TextureManager::instance().updateTexture("Terrain", m_StaticTerrain);
}

void Terrain::draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const {
	sf::Sprite p;
	p.setTexture(*TextureManager::instance().getTexture("Terrain"));
	
	p_Target.draw(p);
}