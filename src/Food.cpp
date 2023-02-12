#include"../include/Food.h"

// The Food.h file has been included above, so that Food.cpp has access to all of the information stored within Food.h.


Food::Food()
{

	// The below if statement will load the image for BatterySkin.png to be applied to the wall sprites.
	// The cout statement is used for bug testing to advise if the texture can be loaded and will print the message to the console if it does not load.

	if (!foodTex.loadFromFile(".\\assets\\textures\\BatterySkin.png"))
	{

		cout << "Could not load image (food)" << endl;

	}

	// Because of the below statement, the texture will not be repeated in each sprite, as this only needs to be applied once per sprite.
	foodTex.setRepeated(false);

}

// The below FloatRect will return the GlobalBounds for the food items, which is used for collision detection with the snake.

FloatRect Food::foodBoundary()
{

	return edible.getGlobalBounds();

}

// The below function allows for the texture, texture size and position of the sprites to be implemented. The sprite position is input via the Gameplay class, so that each food item has a different spawn location.

void Food::foodBlock(sf::Vector2f position)
{

	edible.setTexture(foodTex);
	edible.setTextureRect(sf::IntRect(0, 0, 50, 50));
	edible.setPosition(position);

}

// The below function will allow for the food items to be drawn to the screen via the Gameplay class.

void Food::foodDraw(sf::RenderWindow& window)
{

	window.draw(edible);

}