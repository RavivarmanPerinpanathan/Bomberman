#ifndef AUDIO_HH_
# define AUDIO_HH_

#include <SFML/Audio.hpp>

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

  void (Audio::*PFTab_[3])();

  void playMusic(size_t);

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
  
private:
  sf::Music *introMusic_;
  sf::Music *inGameMusic_;
  sf::Music *gameOverMusic_;
  
  //  sf::SoundBuffer bombSoundBuffer_;
  //  sf::Sound bombSound_;
};
  
# endif /* !AUDIO_HH_ */
  
