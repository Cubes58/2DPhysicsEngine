/**
@file AudioManager.h
@brief Manages the game's audio (background music, and sound effects).
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

	/*!
		\brief Constructor.
		\param p_MusicFileLocation the file location of the music file.
	*/
	AudioManager(const std::string &p_MusicFileLocation);
	~AudioManager(); //!< Destructor.

	/*!
		\brief Loads a music file.
		\param p_PathToAudioFile path to the audio file.
	*/
	void loadMusicFile(const std::string &p_PathToAudioFile);

	/*!
		\brief Loads a sound effect, from a file. 
		\param p_Name the name given for the identifier, when the sound effect is loaded in.
		\param p_PathToAudioFile the path to the audio file.
	*/
	void loadSoundEffect(const std::string &p_Name, const std::string &p_PathToAudioFile);

	/*!
		\brief Processes key presses, action any keys.
		\param p_Name the name of the sound effect, stored in the m_SoundEffects map.
		\return sf::Sound returns the a sound object to be played. 
	*/
	sf::Sound getSoundEffect(const std::string &p_Name) const; //!< Returns a sound effect.
	sf::Music *getBackgroundMusic(); //!< Returns a pointer to the background music.

	// Delete the copy and assignment operators.
	AudioManager(AudioManager const&) = delete; //!< Delete copy operator.
	AudioManager& operator=(AudioManager const&) = delete; //!< Delete assignment operator.
};