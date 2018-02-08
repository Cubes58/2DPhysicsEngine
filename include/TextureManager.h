#pragma once

#include <string>
#include <map>

#include <SFML/Graphics/Texture.hpp>

class TextureManager {
private:
	std::map<std::string, sf::Texture> m_Textures;

	sf::Image m_Terrain;

	TextureManager();
public:
	static TextureManager &instance();

	void createTexture(const std::string &p_Name, sf::Image p_Image);
	const sf::Texture *getTexture(const std::string &p_Name) const;
	void loadTexture(const std::string &p_Name, const std::string &p_PathToTextureFile);
	void updateTexture(const std::string &p_Name, sf::Image p_Image);

	sf::Vector2u getTextureSize(const std::string &p_Name) const;	

	void loadTerrain(const std::string &p_FileLocation);
	sf::Image &getTerrain();

	//Delete the copy and assignment operators.
	TextureManager(TextureManager const&) = delete;
	TextureManager& operator=(TextureManager const&) = delete;
};