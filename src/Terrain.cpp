#include "Terrain.h"

Terrain::Terrain() : m_StaticTerrain(TextureManager::instance().getTerrain()) {
	TextureManager::instance().createTexture("Terrain", m_StaticTerrain);
}

void Terrain::draw(sf::RenderTarget &p_Target, sf::RenderStates p_States) const {
	sf::Sprite p;
	p.setTexture(*TextureManager::instance().getTexture("Terrain"));
	
	p_Target.draw(p);
}