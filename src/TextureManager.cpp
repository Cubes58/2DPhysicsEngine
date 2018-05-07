#include "TextureManager.h"

TextureManager::TextureManager() {
	loadTexturesFromFolder("./assets/textures");
	loadTexturesFromFolder("./assets/scenes");
}

TextureManager::~TextureManager() {

}

TextureManager &TextureManager::instance() {
	static TextureManager instance;

	return instance;
}

// Reference: http://www.martinbroadhurst.com/list-the-files-in-a-directory-in-c.html
int TextureManager::loadTexturesFromFolder(const std::string &p_FolderLocation) {
	std::vector<std::pair<std::string, std::string>> files;
	
	std::experimental::filesystem::path pathLocation(p_FolderLocation);
	std::experimental::filesystem::directory_iterator start(pathLocation);
	std::experimental::filesystem::directory_iterator end;
	std::transform(start, end, std::back_inserter(files), PathLeafString());
	
	for (auto &i : files) {
		std::string fileLocation = p_FolderLocation + "/"+ i.first;
		loadTexture(i.first.substr(0, i.first.size() - i.second.size()), fileLocation);
	}

	return files.size();
}

bool TextureManager::loadTexture(const std::string &p_Name, const sf::Image &p_Image, const std::string &p_OriginalImageFileLocation) {
	if (p_Image.getSize().x != 0 && p_Image.getSize().y != 0) {
		sf::Texture newTexture;
		newTexture.loadFromFile(p_OriginalImageFileLocation);	// Must have an image there, that's the same size, to update.
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

bool TextureManager::updateTexture(const std::string &p_Name, sf::Image p_Image) {
	std::map<std::string, sf::Texture>::iterator iter = m_Textures.find(p_Name);

	if (iter != m_Textures.end()) {
		iter->second.update(p_Image);
		return true;
	}
	return false;
}

sf::Vector2u TextureManager::getTextureSize(const std::string &p_Name) {
	std::map<std::string, sf::Texture>::iterator iter = m_Textures.find(p_Name);

	if (iter != m_Textures.end()) 
		return (iter->second.getSize());
	
	return sf::Vector2u(0, 0);
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