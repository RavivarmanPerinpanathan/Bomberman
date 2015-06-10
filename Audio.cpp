#include "Audio.hh"

Audio::Audio()
{
  this->introMusic_ = new sf::Music;
  this->inGameMusic_ = new sf::Music;
  this->gameOverMusic_ = new sf::Music;
  //  this->bombSoundBuffer_ = new sf::SoundBuffer;  
  //  this->bombSound_ = new sf::Sound;

  introMusic_->openFromFile("sounds/introMusic.ogg");
  inGameMusic_->openFromFile("sounds/inGameMusic.ogg");
  gameOverMusic_->openFromFile("sounds/gameOverMusic.ogg");
  //  bombSoundBuffer_.LoadFromFile():

  this->PFTab_[0] = &Audio::playIntroMusic;
  this->PFTab_[1] = &Audio::playInGameMusic;
  this->PFTab_[2] = &Audio::playGameOverMusic;
}

Audio::~Audio()
{
  delete introMusic_;
  delete inGameMusic_;
  delete gameOverMusic_;
}

void Audio::playMusic(size_t music)
{
  (this->*PFTab_[music])();
}

void Audio::playIntroMusic()
{
  this->introMusic_->play();
}

void Audio::playInGameMusic()
{
  this->inGameMusic_->play();
}

void Audio::playGameOverMusic()
{
  this->gameOverMusic_->play();
}

void Audio::stopIntroMusic()
{
 this->introMusic_->stop();
}

void Audio::stopInGameMusic()
{
  this->inGameMusic_->stop();
}

void Audio::stopGameOverMusic()
{
  this->gameOverMusic_->stop();
}

void Audio::setIntroMusicVolume(float volume)
{
  this->introMusic_->setVolume(volume);
}

void Audio::setInGameMusicVolume(float volume)
{
  this->inGameMusic_->setVolume(volume);
}

void Audio::setGameOverMusicVolume(float volume)
{
  this->gameOverMusic_->setVolume(volume);
}
