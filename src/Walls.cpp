#include "../include/Walls.h"

// The Walls.h file has been included above, so that Walls.cpp has access to all of the information stored within Walls.h.

Walls::Walls()
{
	// The below if statement will load the image for WallSkin.png to be applied to the wall sprites.
	// The cout statement is used for bug testing to advise if the texture can be loaded and will print the message to the console if it does not load.
	
	if (!wallTex.loadFromFile(".\\assets\\textures\\WallSkin.png"))
	{

		cout << "Could not load image (walls)" << endl;

	}

	// The below statement will repeat the wallTex texture for all of the sprites created for the walls.
	wallTex.setRepeated(true);

}

// The below function will set the texture for the top wall, the length of the wall for the textures to be applied to and the starting position of the first section. Once initiated, it will then draw the top wall for the arena.

void Walls::Top(sf::RenderWindow& window)
{
	top.setTexture(wallTex);
	top.setTextureRect(sf::IntRect(0, 0, 750, 50));
	top.setPosition(0, 0);
	window.draw(top);
}

// The below function will set the texture for the bottom wall, the length of the wall for the textures to be applied to and the starting position of the first section. Once initiated, it will then draw the bottom wall for the arena.

void Walls::Bottom(sf::RenderWindow& window)
{
	bottom.setTexture(wallTex);
	bottom.setTextureRect(sf::IntRect(0, 0, 750, 50));
	bottom.setPosition(0, 550);
	window.draw(bottom);
}

// The below function will set the texture for the left wall, the length of the wall for the textures to be applied to and the starting position of the first section. Once initiated, it will then draw the left wall for the arena.

void Walls::Left(sf::RenderWindow& window)
{
	left.setTexture(wallTex);
	left.setTextureRect(sf::IntRect(0, 0, 50, 500));
	left.setPosition(0, 50);
	window.draw(left);
}

// The below function will set the texture for the right wall, the length of the wall for the textures to be applied to and the starting position of the first section. Once initiated, it will then draw the right wall for the arena.

void Walls::Right(sf::RenderWindow& window)
{
	right.setTexture(wallTex);
	right.setTextureRect(sf::IntRect(0, 0, 50, 600));
	right.setPosition(750, 0);
	window.draw(right);
}

// The below FloatRect will return the GlobalBounds for the top wall, which is used for collision detection with the snake.

FloatRect Walls::topPos()
{

	return top.getGlobalBounds();

}

// The below FloatRect will return the GlobalBounds for the right wall, which is used for collision detection with the snake.

FloatRect Walls::rightPos()
{
	return right.getGlobalBounds();
}

// The below FloatRect will return the GlobalBounds for the left wall, which is used for collision detection with the snake.

FloatRect Walls::leftPos()
{
	return left.getGlobalBounds();
}

// The below FloatRect will return the GlobalBounds for the bottom wall, which is used for collision detection with the snake.

FloatRect Walls::bottomPos()
{
	return bottom.getGlobalBounds();
}