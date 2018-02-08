#pragma once

#include <map>

#include <SFML\Audio\SoundBuffer.hpp>
#include <SFML\Audio\Sound.hpp>
#include <SFML\Audio\Music.hpp>

class AudioManager {
private:
	std::map<std::string, sf::SoundBuffer> m_SoundEffects;
	sf::Music m_BackgroundMusic;
public:
	AudioManager();

	void LoadMusicFile(const std::string &p_PathToAudioFile);
	void LoadSoundEffect(const std::string &p_Name, const std::string &p_PathToAudioFile);

	sf::Sound GetSoundEffect(const std::string &p_Name) const;
	sf::Music *GetBackgroundMusic();

	//Delete the copy and assignment operators.
	AudioManager(AudioManager const&) = delete;
	AudioManager& operator=(AudioManager const&) = delete;
};