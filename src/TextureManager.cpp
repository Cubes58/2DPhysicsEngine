#include "TextureManager.h"

TextureManager::TextureManager() {
	loadTexture("Bomb", "./assets/textures/Bomb.png");
	loadTexture("SoldierTemplate", "./assets/textures/SoldierTemplate.png");
	loadTexture("RedSoldier", "./assets/textures/RedSoldier.png");
	loadTexture("BlueSoldier", "./assets/textures/BlueSoldier.png");
	loadTexture("Background", "./assets/scenes/MapOneBackground.png");
}

TextureManager::~TextureManager() {

}

TextureManager &TextureManager::instance() {
	static TextureManager instance;

	return instance;
}

bool TextureManager::loadTexture(const std::string &p_Name, const sf::Image &p_Image, const std::string &p_OriginalImageFileLocation) {
	if (p_Image.getSize().x != 0 && p_Image.getSize().y != 0) {
		sf::Texture newTexture;
		newTexture.loadFromFile(p_OriginalImageFileLocation);	// Must have an image there, to update.
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
	if (newTexture.loadFromFile(p_PathToTextureFile)) {
		newTexture.setSmooth(true);
		newTexture.setRepeated(true);
		m_Textures.insert(std::pair<std::string, sf::Texture>(p_Name, newTexture));	
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



/*
std::vector<std::string> FileHelper::getDirectoryNameList(std::string p_FilePath)
{
//Reference: http://www.martinbroadhurst.com/list-the-files-in-a-directory-in-c.html
std::vector<std::string> names;

p_FilePath.append("\\*");

WIN32_FIND_DATA fileData;
HANDLE hFind;
hFind = FindFirstFile(p_FilePath.c_str(), &fileData);
if (hFind != INVALID_HANDLE_VALUE) {
std::cout << "Directory found" << std::endl;
std::cout << "Files in directory:" << std::endl;
do {
names.push_back(p_FilePath + "\\" + fileData.cFileName);
std::cout << p_FilePath + "\\" + fileData.cFileName << std::endl;
} while (FindNextFile(hFind, &fileData) != 0);
}
else {
std::cout << "No directory found" << std::endl;
}
FindClose(hFind);
return names;
}


Sometimes . and ... are considered files.

cast to c++ string
*/