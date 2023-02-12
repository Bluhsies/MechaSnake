#pragma once

// This is the Food class, which has all of the necessary functions available to create the food for Snake.
// Included is the SFML/Graphics.hpp, which allows for the creating, rendering and drawing of the shapes, sprites and textures associated with the game.

#include<iostream>
#include"SFML/Graphics.hpp"

using namespace std;
using namespace sf;

class Food
{

private:

	// These are the private variables used to obtain the texture for the snake food and for the sprite parameters to be set in foodBlock();.

	sf::Texture foodTex;

	sf::Sprite edible;

public:

	// The constructor Food(); has been set as a public function, so that the other functions can access the data stored within, such as the ability to load textures.
	
	Food();

	// The below function will draw the food to the screen.

	void foodDraw(sf::RenderWindow& window);

	// The below function will allow for the texture, position and setTextureRect to be set for the food.

	void foodBlock(sf::Vector2f position);

	// The below function will allow for the GlobalBounds of the food sprites to be obtained for collision detection.

	FloatRect foodBoundary();




};
