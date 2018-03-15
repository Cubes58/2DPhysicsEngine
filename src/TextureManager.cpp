#include "TextureManager.h"

TextureManager::TextureManager() {
	//Load from a text file.

	//Populate the texture vector.
	//loadTexture("BlackBlock", "./assets/textures/BlackBlock.png");
}

TextureManager &TextureManager::instance() {
	static TextureManager instance;

	return instance;
}

bool TextureManager::loadTexture(const std::string &p_Name, const sf::Image &p_Image) {
	if (p_Image.getSize().x != 0 && p_Image.getSize().y != 0) {
		sf::Texture newTexture;
		newTexture.loadFromFile("./assets/scenes/MapOne.png");	// Must have an image there, to update.
		newTexture.setSmooth(true);
		newTexture.setRepeated(true);
		newTexture.update(p_Image);
		m_Textures.insert(std::pair<std::string, sf::Texture>(p_Name, newTexture));

		return true;
	}
	return false;
}

bool TextureManager::loadTexture(const std::string &p_Name, const std::string &p_PathToTextureFile) {
	sf::Texture newTexture;
	if (newTexture.loadFromFile(p_PathToTextureFile)) {										//Check to make sure it can find the texture file.
		newTexture.setSmooth(true);
		newTexture.setRepeated(true);
		m_Textures.insert(std::pair<std::string, sf::Texture>(p_Name, newTexture));			//Load a pair into the map.
		return true;
	}
	return false;
}

const sf::Texture *TextureManager::getTexture(const std::string &p_Name) {
	std::map<std::string, sf::Texture>::iterator iter = m_Textures.find(p_Name);
	
	if (iter != m_Textures.end())
		return &iter->second;

	return nullptr;
}

void TextureManager::updateTexture(const std::string &p_Name, sf::Image p_Image) {
	m_Textures.at(p_Name).update(p_Image);
}

sf::Vector2u TextureManager::getTextureSize(const std::string &p_Name) const {
	return ((m_Textures.at(p_Name)).getSize());
}