#include"../include/Snake.h"
#include"../include/Food.h"

// Above are the included files for the Snake and Food classes. The Food class has been included, as the Snake classes uses the Food class for collision detection with the food pieces.

Snake::Snake()
{
	
	// The below if statement will load the image for MechaSnakeSkin.png to be applied to the wall sprites.
	// The cout statement is used for bug testing to advise if the texture can be loaded and will print the message to the console if it does not load.

	if (!snakeTex.loadFromFile(".\\assets\\textures\\MechaSnakeSkin.png"))
	{

		cout << "Could not load image (snake)" << endl;

	}

	// Because of the below statement, the texture will not be repeated in each sprite, as this only needs to be applied once per sprite.
	snakeTex.setRepeated(false);

}

// The below boolean function will check to see if an object of the Snake classes Bounding Box (GlobalBounds) are intersecting with an object from the Food classes Bounding Box (Global Bounds).

bool Snake::collidesWith(Food *snack)
{

	if (snakeHead.getGlobalBounds().intersects(snack->foodBoundary()))
	{
		return true;
	} return false;

}

// The below boolean function will check to see if the Global bounds of an object of the Snake class are interseting with another object from the Snake class.

bool Snake::selfCollision(Snake* serpent)
{

	if (snakeHead.getGlobalBounds().intersects(serpent->getPos()))
	{
		return true;
	} return false;

}

// The below function will allow for the texture, texturerect and position of the snake sprites to be made. The position is input manually via the Gameplay class.

void Snake::SnakeHead(sf::Vector2f position)
{

	snakeHead.setTexture(snakeTex);
	snakeHead.setTextureRect(sf::IntRect(0, 0, 50, 50));
	snakeHead.setPosition(position);

}

// The below function allows for the Snake class sprites to be drawn to the screen in the Gameplay class.

void Snake::SnakeDraw(sf::RenderWindow& window)
{

	window.draw(snakeHead);

}

// The below function will take the distance variable, which determines the speed of the player movement and apply it to the objects made from the Snake Class, as long as this function is set in the Gameplay class.

void Snake::MoveSnake(sf::Vector2f distance)
{

	snakeHead.move(distance);

}

// The below function will retrieve the GlobalBounds of Snake class objects for collision detection.

FloatRect Snake::getPos()
{

	return snakeHead.getGlobalBounds();

}







