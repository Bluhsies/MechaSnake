#pragma once

// This is the Snake class, which has all of the necessary functions available to create the Snake for Snake.
// Included is the SFML/Graphics.hpp, which allows for the creating, rendering and drawing of the shapes, sprites and textures associated with the game.

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Food.h"
#include <vector>

using namespace std;
using namespace sf;

class Snake
{

private:

	// These are the private variables which are used to set the texture and assign the texture to particular sprites, which are drawn to the screen for the Snake head and body.
	
	sf::Texture snakeTex;

	sf::Sprite snakeHead;
	

public:

	// The constructor Snake(); has been set as a public function, so that the other functions can access the data stored within, such as the ability to load textures.

	Snake();

	// The two boolean functions below are used for collision detection. The first, is to check to see if the snake head collides with an object of the Food class. The second is to see if the snake head collides with another object from the Snake class.

	bool collidesWith(Food *snack);

	bool selfCollision(Snake* serpent);

	// The below function allows for the texture to be set for the snake objects, TextureRect and for the position of the snake to be manually input in the Gameplay class.

	void SnakeHead(sf::Vector2f position);

	// The below function allows for the Snake sections to be drawn to the screen.

	void SnakeDraw(sf::RenderWindow& window);
	
	// The below function is used for the user input of the arrow keys to determine the speed of the Snake objects in the Gameplay class.

	void MoveSnake(sf::Vector2f distance);

	// The below function allows for the GlobalBounds of the snake pieces to be acquired for collision detection.

	FloatRect getPos();

	

	

};
