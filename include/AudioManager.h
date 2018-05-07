/**
@file AudioManager.h
*/
#pragma once

#include <map>

#include <SFML\Audio\SoundBuffer.hpp>
#include <SFML\Audio\Sound.hpp>
#include <SFML\Audio\Music.hpp>

class AudioManager {
private:
	std::map<std::string, sf::SoundBuffer> m_SoundEffects; //!< A map of sound buffers, for sound effect. A string is used for the identifier. 
	sf::Music m_BackgroundMusic; //!< Background music, object. 
public:
	AudioManager() = default; //!< Constructor.
	AudioManager(const std::string &p_MusicFileLocation); //!< Constructor.
	~AudioManager(); //!< Destructor.

	void loadMusicFile(const std::string &p_PathToAudioFile); //!< Loads a music file.
	void loadSoundEffect(const std::string &p_Name, const std::string &p_PathToAudioFile); //!< Loads a sound effect, from a file. 

	sf::Sound getSoundEffect(const std::string &p_Name) const; //!< Returns a sound effect.
	sf::Music *getBackgroundMusic(); //!< Returns a pointer to the background music.

	// Delete the copy and assignment operators.
	AudioManager(AudioManager const&) = delete; //!< Delete copy operator.
	AudioManager& operator=(AudioManager const&) = delete; //!< Delete assignment operator.
};