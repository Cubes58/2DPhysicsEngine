/**
@file TextureManager.h
*/
#pragma once

#include <string>
#include <map>

#include <SFML/Graphics/Texture.hpp>

class TextureManager {
private:
	std::map<std::string, sf::Texture> m_Textures; //!< Map of textures. Names are used for the identifier, to texture objects.

	TextureManager(); //!< Constructor.
	~TextureManager(); //!< Destructor.
public:
	static TextureManager &instance(); //!< Returns an instance of Texture manager.

	bool loadTexture(const std::string &p_Name, const sf::Image &p_Image, const std::string &p_OriginalImageFileLocation); //!< Loads a texture, using an image.
	const sf::Texture *getTexture(const std::string &p_Name); //!< Returns a pointer a texture, in the map. Returns nullptr, if the texture wasn't found.
	bool loadTexture(const std::string &p_Name, const std::string &p_PathToTextureFile); //!< Loads a texture, from a file.
	void updateTexture(const std::string &p_Name, sf::Image p_Image); //!< Updates a texture's pixels/image, using an image object.

	sf::Vector2u getTextureSize(const std::string &p_Name) const; //!< Returns a texture's size.

	// Delete the copy and assignment operators.
	TextureManager(TextureManager const&) = delete; //!< Copy operator, deleted.
	TextureManager& operator=(TextureManager const&) = delete; //!< Assignment operator, deleted.
};