#pragma once

#include <string>
#include <map>

#include <SFML/Graphics/Texture.hpp>


class TextureManager {
private:
	std::map<std::string, sf::Texture> m_Textures;

	TextureManager();
public:
	static TextureManager &instance();

	const sf::Texture *getTexture(const std::string &p_Name) const;
	void loadTexture(const std::string &p_Name, const std::string &p_PathToTextureFile);

	const sf::Vector2u *getTextureSize(const std::string &p_Name) const;

	static unsigned char loadBMP();

	//Delete the copy and assignment operators.
	TextureManager(TextureManager const&) = delete;
	TextureManager& operator=(TextureManager const&) = delete;
};