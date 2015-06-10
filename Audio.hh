#ifndef AUDIO_HH_
# define AUDIO_HH_

# include <SFML/Audio.hpp>

# define NBMUSIC 3

typedef enum	e_music
  {
    INTRO = 0,
    INGAME,
    GAMEOVER,
  }		t_music;

class Audio
{
public:
  Audio();
  ~Audio();

  void (Audio::*PFArr_[NBMUSIC])(); // Play Functions Array.
  void (Audio::*SFArr_[NBMUSIC])(); // Stop Functions Array.
  void (Audio::*SVFArr_[NBMUSIC])(float); // Set Volume Functions Array.

  void playMusic(size_t);
  void stopMusic(size_t);
  void setVolume(size_t, float);

private:
  sf::Music *introMusic_;
  sf::Music *inGameMusic_;
  sf::Music *gameOverMusic_;
  //  sf::SoundBuffer bombSoundBuffer_;
  //  sf::Sound bombSound_;
  
  void playIntroMusic();
  void playInGameMusic();
  void playGameOverMusic();
  //  void playBombSound();

  void stopIntroMusic();
  void stopInGameMusic();
  void stopGameOverMusic();

  void setIntroMusicVolume(float);
  void setInGameMusicVolume(float);
  void setGameOverMusicVolume(float);


};
  
# endif /* !AUDIO_HH_ */
  
