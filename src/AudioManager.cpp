#include "AudioManager.h"

AudioManager::AudioManager() {

}

AudioManager::~AudioManager() {

}

void AudioManager::loadMusicFile(const std::string &p_PathToAudioFile) {
	if (m_BackgroundMusic.openFromFile(p_PathToAudioFile))
		return;
}

void AudioManager::loadSoundEffect(const std::string &p_Name, const std::string &p_PathToAudioFile) {
	sf::SoundBuffer buffer;
	if (buffer.loadFromFile(p_PathToAudioFile))
		m_SoundEffects.insert(std::pair<std::string, sf::SoundBuffer>(p_Name, buffer));
}

sf::Sound AudioManager::getSoundEffect(const std::string &p_Name) const {
	sf::Sound sound;
	sound.setBuffer(m_SoundEffects.at(p_Name));

	return sound;
}

sf::Music *AudioManager::getBackgroundMusic() {
	return &m_BackgroundMusic;
}