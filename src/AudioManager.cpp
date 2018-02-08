#include "AudioManager.h"

AudioManager::AudioManager() {

}

void AudioManager::LoadMusicFile(const std::string &p_PathToAudioFile) {
	if (m_BackgroundMusic.openFromFile(p_PathToAudioFile))
		;
}

void AudioManager::LoadSoundEffect(const std::string &p_Name, const std::string &p_PathToAudioFile) {
	sf::SoundBuffer buffer;
	if (buffer.loadFromFile(p_PathToAudioFile))
		m_SoundEffects.insert(std::pair<std::string, sf::SoundBuffer>(p_Name, buffer));
}

sf::Sound AudioManager::GetSoundEffect(const std::string &p_Name) const {
	sf::Sound sound;
	sound.setBuffer(m_SoundEffects.at(p_Name));

	return sound;
}

sf::Music *AudioManager::GetBackgroundMusic() {
	return &m_BackgroundMusic;
}