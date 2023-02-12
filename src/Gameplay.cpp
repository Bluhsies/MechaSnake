#include "../include/Gameplay.h"
#include <iostream>

// Included is the Gameplay.h file, which includes all other .h files associated with the project, to allow the game to be implemented.

using namespace std;

Gameplay::Gameplay()
{


}

void Gameplay::GameOn()
{
	// The below object will render the window.

	sf::RenderWindow window(sf::VideoMode(1200, 600), "Snake!");

	// The below Vectoe2f is used to determine the speed at which the snakehead will move.

	sf::Vector2f snakeMove({ 0.1f, 0.0f });
	
	snakeScore.settingsUI();
	snakeScore.UIScoreLabel();

	win.WinLabel();
	lose.LoseLabel();

	// The two below objects are used to instantiate the music and sound effects from the Audio class.

	Audio gamePlayMusic;
	Audio effects;
	gamePlayMusic.playIntro();

	// Below is where the body parts for the snake are originally placed off-screen.
	
	body1.SnakeHead({ 1000, 1000 });
	body2.SnakeHead({ 1000, 1000 });
	body3.SnakeHead({ 1000, 1000 });
	body4.SnakeHead({ 1000, 1000 });
	body5.SnakeHead({ 1000, 1000 });

	// The below is where the body parts are stored within the vector<Snake*> mentioned in the .h file.

	snakeParts.push_back(&body1);
	snakeParts.push_back(&body2);
	snakeParts.push_back(&body3);
	snakeParts.push_back(&body4);
	snakeParts.push_back(&body5);

	// The below is where the batteries (snacks) are stored within the vector<Food*> mentioned in the .h file.

	batteries.push_back(&snack1);
	batteries.push_back(&snack2);
	batteries.push_back(&snack3);
	batteries.push_back(&snack4);
	batteries.push_back(&snack5);

	// The below is where the battery positions are set on the screen when the window is rendered.

	snack1.foodBlock({ 200, 150 });
	snack2.foodBlock({ 500, 300 });
	snack3.foodBlock({ 300, 400 });
	snack4.foodBlock({ 350, 500 });
	snack5.foodBlock({ 400, 50 });

	// The below is where the snake head is rendered on the screen.

	snakeBody.SnakeHead({ 50, 50 });

	// Whilst the window is open, the snake head will utilise the value stored within snakeMove to move, via the MoveSnake function.

	while (window.isOpen())
	{
		sf::Event event;

		snakeBody.MoveSnake(snakeMove);

		

		while (window.pollEvent(event))
		{



			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Up:                           // The switch statement to the left will allow for the automatic movement of the snake head once the hilst is rendered and whilst the window continues to be open.
					snakeMove = { 0.f, -0.1 };
					break;
				case sf::Keyboard::Down:
					snakeMove = { 0.f,0.1 };
					break;
				case sf::Keyboard::Left:
					snakeMove = { -0.1, 0.f };
					break;
				case sf::Keyboard::Right:
					snakeMove = { 0.1, 0.f };
					break;

				default:
					break;
				}
			}


		}

		// The below for loop will check to see when a battery is collected by the snake head and move the battery somewhere off screen. It will then increase the score value by 1, print a body part to the screen (top left) and play the battery collection sound.

		for (int i = 0; i < batteries.size(); i++)
		{
			if (snakeBody.collidesWith(batteries[i]))
			{

				

				batteries[i]->foodBlock({ 1000, 1000 });
				batteryCollection++;
				MechaSnakeScore.str("");
				MechaSnakeScore << " " << batteryCollection;
				snakeScore.UIScoreText(MechaSnakeScore.str());
				snakeParts[i]->SnakeHead({ move += 50,50 });

				
				effects.playLife();
					


			}

			
		}

		// The below for loop will check to see if the snake head collides with any of the body parts and move both the head and paret off the screen. It will then increase the loseVariable by 1 to assist with printing the lose message.
		// Furthermore, it will play the death sound and stop the music for the game.

		for (int i = 0; i < snakeParts.size(); i++)
		{
			if (snakeBody.selfCollision(snakeParts[i]))
			{

				snakeParts[i]->SnakeHead({ 1500, 1500 });

				snakeBody.SnakeHead({ 2000,2000 });

				loseVariable++;

				effects.playDeath();

				gamePlayMusic.stopIntro();
			}
		}

		// The below if statement will check to see if the snake head collides with any of the arena walls. If it does, it will be move off-screen, increase the loseVariable by 1, play the death sound and stop the game music.

		if (snakeBody.getPos().intersects(arena.topPos()) ||
			snakeBody.getPos().intersects(arena.bottomPos()) ||
			snakeBody.getPos().intersects(arena.rightPos()) ||
			snakeBody.getPos().intersects(arena.leftPos()))
		{
			snakeBody.SnakeHead({ 1500,1500 });

			loseVariable++;

			effects.playDeath();

			gamePlayMusic.stopIntro();

		}
		
		// This will clear the current window and then render it with a black background.

		window.clear(sf::Color::Black);


		// This is where the objects for the game are rendered to the window.

		arena.Top(window);
		arena.Bottom(window);
		arena.Left(window);
		arena.Right(window);
		snakeBody.SnakeDraw(window);
		body1.SnakeDraw(window);
		body2.SnakeDraw(window);
		body3.SnakeDraw(window);
		body4.SnakeDraw(window);
		body5.SnakeDraw(window);
		snack1.foodDraw(window);
		snack2.foodDraw(window);
		snack3.foodDraw(window);
		snack4.foodDraw(window);
		snack5.foodDraw(window);
		snakeScore.UIDraw(window);

		// The below if statement will check to see if the score is 5 and if it is, it will stop the game music, stop the snake head from moving and print the win message to the bottom right of the screen.

		if (batteryCollection == 5)
		{

			win.WinDraw(window);
			snakeMove = { 0.f,0.f };
			gamePlayMusic.stopIntro();

		}

		// The below if statement will check to see if the loseVariable has increased by 1 and if it has, it will print the lose message to the bottom right of the screen.
		
		if (loseVariable == 1)
		{
			lose.LoseDraw(window);
		}
		
		// The below will display what has been rendered to the screen.

		window.display();
	}



	

}