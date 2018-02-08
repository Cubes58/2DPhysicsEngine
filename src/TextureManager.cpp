#include "TextureManager.h"

TextureManager::TextureManager() {
	//Load from a text file

	//Populate the texture vector.
	//LoadTexture("BlackBlock", "./assets/textures/BlackBlock.png");
}

TextureManager& TextureManager::Instance() {
	static TextureManager instance;

	return instance;
}

const sf::Texture* TextureManager::GetTexture(const std::string &p_Name) const {
	return &m_Textures.at(p_Name);
}

void TextureManager::LoadTexture(const std::string &p_Name, const std::string &p_PathToTextureFile) {
	sf::Texture newTexture;
	if (newTexture.loadFromFile(p_PathToTextureFile)) {										//Check to make sure it can find the texture file.
		newTexture.setSmooth(true);
		newTexture.setRepeated(true);
		m_Textures.insert(std::pair<std::string, sf::Texture>(p_Name, newTexture));			//Load a pair into the map.
	}
}

const sf::Vector2u* TextureManager::GetTextureSize(const std::string &p_Name) const {
	return (&(m_Textures.at(p_Name)).getSize());
}