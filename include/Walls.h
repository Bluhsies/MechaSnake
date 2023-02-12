#pragma once

// This is the Walls class, which has all of the necessary functions available to create the arena walls for Snake.
// Included is the SFML/Graphics.hpp, which allows for the creating, rendering and drawing of the shapes, sprites and textures associated with the game.

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Walls
{

private:

	// These are the private variables which are used to set the texture and assign the texture to particular sprites, which are drawn to the screen for the 4 arena walls.

	sf::Texture wallTex;
	sf::Sprite top;
	sf::Sprite bottom;
	sf::Sprite left;
	sf::Sprite right;

public:

	// The constructor Walls(); has been set as a public function, so that the other functions can access the data stored within, such as the ability to load textures.

	Walls();

	// Below are the function prototypes for the FloatRects for each of the 4 walls, to get their GlobalBounds.

	FloatRect topPos();
	FloatRect rightPos();
	FloatRect leftPos();
	FloatRect bottomPos();

	// The following 4 function prototypes are so the walls can be drawn to the screen via the Gameplay class, once and object of the Walls class has been created in Gameplay.cpp.

	void Top(sf::RenderWindow& window);
	void Bottom(sf::RenderWindow& window);
	void Left(sf::RenderWindow& window);
	void Right(sf::RenderWindow& window);


};
