#include "../include/Audio.h"

// Included is the Audio.h file, so that the Audio.cpp file has access to all information in Audio.h.

Audio::Audio()
{

	// The below if statements will check to see if the music and sound effects can be loaded and if not, an error message will be printed to the console to advise of this.

	if (!gameMusic.openFromFile(".\\assets\\Audio\\GameMusicNew.wav"))
	{

		cout << "Music not working (intro)" << endl;

	}

	if (!bufferTwo.loadFromFile(".\\assets\\Audio\\DeathSound.wav"))
	{

		cout << "Death error" << endl;

	}

	if (!buffer.loadFromFile(".\\assets\\Audio\\RechargeSound.wav"))
	{

		cout << "Life error" << endl;

	}

}

// The below function will play the game music.

void Audio::playIntro()
{
	gameMusic.play();
}

// The below function will stop thr game music from playing.

void Audio::stopIntro()
{

	gameMusic.stop();

}

// The below function will play the death sound when the snake head collides with a wall or body part, implemented in the Gameplay class.

void Audio::playDeath()
{

	death.setBuffer(bufferTwo);

	death.play();

}

// The below function will play the life sound when the snake head collides with a battery, implemented in the Gameplay class. This will play each time a battery is collected, due to the buffer which has been set.

void Audio::playLife()
{

	life.setBuffer(buffer);

	life.play();

}




