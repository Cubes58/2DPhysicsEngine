#include "TextureManager.h"

TextureManager::TextureManager() {
	//Load from a text file.

	// Load the Terrain.
	loadTerrain("./assets/scenes/Default.png");

	//Populate the texture vector.
	//loadTexture("BlackBlock", "./assets/textures/BlackBlock.png");
}

TextureManager& TextureManager::instance() {
	static TextureManager instance;

	return instance;
}

void TextureManager::createTexture(const std::string &p_Name, sf::Image p_Image) {
	sf::Texture newTexture;
	newTexture.loadFromFile("./assets/scenes/Temp.png");	//Must have an image there, to update.
	newTexture.setSmooth(true);
	newTexture.setRepeated(true);
	newTexture.update(p_Image);
	m_Textures.insert(std::pair<std::string, sf::Texture>(p_Name, newTexture));
}

const sf::Texture* TextureManager::getTexture(const std::string &p_Name) const {
	return &m_Textures.at(p_Name);
}

void TextureManager::loadTexture(const std::string &p_Name, const std::string &p_PathToTextureFile) {
	sf::Texture newTexture;
	if (newTexture.loadFromFile(p_PathToTextureFile)) {										//Check to make sure it can find the texture file.
		newTexture.setSmooth(true);
		newTexture.setRepeated(true);
		m_Textures.insert(std::pair<std::string, sf::Texture>(p_Name, newTexture));			//Load a pair into the map.
	}
}

void TextureManager::updateTexture(const std::string &p_Name, sf::Image p_Image) {
	m_Textures.at(p_Name).update(p_Image);
}

sf::Vector2u TextureManager::getTextureSize(const std::string &p_Name) const {
	return ((m_Textures.at(p_Name)).getSize());
}

// Have this in the Terrain? Rename it?
void TextureManager::loadTerrain(const std::string &p_FileLocation) {
	if (m_Terrain.loadFromFile(p_FileLocation))
		return;
	else
		m_Terrain.loadFromFile("./assets/scenes/Default");
}

sf::Image &TextureManager::getTerrain() {
	return m_Terrain;
}