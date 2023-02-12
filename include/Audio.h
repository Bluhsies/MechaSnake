#pragma once

// This is the Food class, which has all of the necessary functions available to create the food for Snake.
// Included is the SFML/Graphics.hpp, which allows for the creating, rendering and drawing of the shapes, sprites and textures associated with the game.
// Included is the SFML/Audio.hpp, which allows for sound (music and effects) to be implemented in the game.

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;

class Audio
{

public:

	// The constructor Audio(); has been set as a public function, so that the other functions can access the data stored within, such as the ability to load music and sound effects.

	Audio();

	// The below function will play the game music.

	void playIntro();

	// The below function will stop the game music.

	void stopIntro();

	// The below function will play the sound effect upon player death.

	void playDeath();

	// The below function will play the sound effect upon the snake head colliding with a battery.

	void playLife();

	

protected:

	// The below variables are used to set the music and sound effects for the game.

	sf::Music gameMusic;
	sf::Sound death;
	sf::SoundBuffer bufferTwo;
	sf::SoundBuffer buffer;
	sf::Sound life;

	

};