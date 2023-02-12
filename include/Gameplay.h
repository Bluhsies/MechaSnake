#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Food.h"
#include "UI.h"
#include "Snake.h"
#include "Walls.h"
#include "Audio.h"

// Included above are all of the .h files for all other classes, as the main gameplay is initialised in the Gameplay class. It will need to take information stored within each class to complete the rendering of the game.

using namespace std;
using namespace sf;

class Gameplay
{

public:

	Gameplay();

	// This is the central function for the Gameplay class and incorporates the different aspects taken from all of the other classes, so that the game can be rendered and played.
	void GameOn();

	// These variables are used for account for the player score, to play the death sound and for the body part sprites to be printed to the screen.
	int batteryCollection = 0;
	int loseVariable = 0;
	float move = 0.f;
	

protected:

	// Below are the objects created from the other classes, for the UI, Snake, Walls and Food. The Sound objects are within the GameOn function already.

	UI snakeScore;
	UI win;
	UI lose;
	std::ostringstream MechaSnakeScore;

	Walls arena;

	std::vector<Snake*> snakeParts;
	Snake body1;
	Snake body2;
	Snake body3;
	Snake body4;
	Snake body5;

	Snake snakeBody;

	std::vector<Food*> batteries;
	Food snack1;
	Food snack2;
	Food snack3;
	Food snack4;
	Food snack5;

};