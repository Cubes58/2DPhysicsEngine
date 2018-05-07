/**
@file TextureManager.h
@brief Manages the game's textures.
*/
#pragma once

#include <string>
#include <map>
#include <algorithm>

#include <experimental/filesystem>
#include <filesystem>
using namespace std::experimental::filesystem::v1;

#include <SFML/Graphics/Texture.hpp>

class TextureManager {
private:
	std::map<std::string, sf::Texture> m_Textures; //!< Map of textures. Names are used for the identifier, to texture objects.

	TextureManager(); //!< Constructor.
	~TextureManager(); //!< Destructor.

	struct PathLeafString {
		/*!
			\brief The file name, and extension of the file, from a filesystem object.
			\param filesystem::directory_entry p_Entry File directory.
		*/
		std::pair<std::string, std::string> operator()(const std::experimental::filesystem::directory_entry &p_Entry) const {
			return std::pair<std::string, std::string>(p_Entry.path().filename().string(), p_Entry.path().extension().string());
		}
	};
public:
	/*
		\brief Returns an instance of Texture manager.
		\return instance of TextureManager, as its a singleton.
	*/
	static TextureManager &instance(); //!< Returns an instance of Texture manager.

	/*!
		\brief Load files (textures) from a folder.
		\param p_FolderLocation folder location of the textures.
		\return int that's the size of how many files were found.
	*/
	int loadTexturesFromFolder(const std::string &p_FolderLocation);

	/*!
		\brief creates/updates a texture from an image.
		\param p_Name name of the (new) texture.
		\param p_Image the image of the new texture.
		\param p_OriginalImageFileLocation file location to the original image.
		\return bool that's true if it created/updates the texture, false otherwise.
	*/
	bool loadTexture(const std::string &p_Name, const sf::Image &p_Image, const std::string &p_OriginalImageFileLocation);

	/*!
		\brief Gets a texture pointer, from the textures stored in the texture manager.
		\param p_Name name of the texture.
		\return texture pointer, pointing to the texture if its found, otherwise it returns a nullptr.
	*/
	const sf::Texture *getTexture(const std::string &p_Name);

	/*!
		\brief Loads a texture.
		\param p_Name name of the texture.
		\param p_PathToTextureFile path to image file.
		\return bool that's true if the texture is loaded, otherwise false.
	*/
	bool loadTexture(const std::string &p_Name, const std::string &p_PathToTextureFile); //!< Loads a texture, from a file.

	/*!
		\brief Load files (textures) from a folder.
		\param p_FolderLocation folder location of the textures.
		\return int that's the size of how many files were found.
	*/
	bool updateTexture(const std::string &p_Name, sf::Image p_Image); //!< Updates a texture's pixels/image, using an image object.

	/*!
		\brief Load files (textures) from a folder.
		\param p_Name name of the texture, stored in the map.
		\return sf::Vector2u the size of the texture.
	*/
	sf::Vector2u getTextureSize(const std::string &p_Name); //!< Returns a texture's size.

	// Delete the copy and assignment operators.
	TextureManager(TextureManager const&) = delete; //!< Copy operator, deleted.
	TextureManager& operator=(TextureManager const&) = delete; //!< Assignment operator, deleted.
};