#pragma once

#include <string>
#include <map>

#include <SFML/Graphics/Texture.hpp>

class TextureManager {
private:
	std::map<std::string, sf::Texture> m_Textures;

	TextureManager();
	~TextureManager();
public:
	static TextureManager &instance();

	bool loadTexture(const std::string &p_Name, const sf::Image &p_Image, const std::string &p_OriginalImageFileLocation);
	const sf::Texture *getTexture(const std::string &p_Name);
	bool loadTexture(const std::string &p_Name, const std::string &p_PathToTextureFile);
	void updateTexture(const std::string &p_Name, sf::Image p_Image);

	sf::Vector2u getTextureSize(const std::string &p_Name) const;	

	// Delete the copy and assignment operators.
	TextureManager(TextureManager const&) = delete;
	TextureManager& operator=(TextureManager const&) = delete;
};