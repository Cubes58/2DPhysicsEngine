#pragma once

#include <string>
#include <map>

#include <SFML/Graphics/Texture.hpp>


class TextureManager {
private:
	std::map<std::string, sf::Texture> m_Textures;

	TextureManager();
public:
	static TextureManager &Instance();

	const sf::Texture *GetTexture(const std::string &p_Name) const;
	void LoadTexture(const std::string &p_Name, const std::string &p_PathToTextureFile);

	const sf::Vector2u *GetTextureSize(const std::string &p_Name) const;

	//Delete the copy and assignment operators.
	TextureManager(TextureManager const&) = delete;
	TextureManager& operator=(TextureManager const&) = delete;
};