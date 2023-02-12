#include "../include/UI.h"
#include <iostream>

// The UI.h file has been included above, so that UI.cpp has access to all of the information stored within UI.h.

using namespace std;

UI::UI()
{
	// The below if statement will check to see if the font 8BITWONDER can be loaded from file and it if cannot, then it will print the message to the console toadvise as such.

	if (!fontage.loadFromFile(".\\assets\\fonts\\8BITWONDER.TTF"))
	{

		cout << "Could not load font" << endl;

	}
	

}

// This function allows you to set the font, character size, position and fill colour for score text.

void UI::settingsUI()
{

	score.setFont(fontage);
	score.setCharacterSize(35);
	score.setPosition({ 1050.f, 100.f });
	score.setFillColor(sf::Color::White);

}

// This function allows you to change the value of the score, increment by one, for each battery consumed by the snake head.

void UI::UIScoreText(const std::string& text)
{
	score.setString(text);
}

// This function is used to set the parameters for the score label.

void UI::UIScoreLabel()
{

	label.setFont(fontage);
	label.setCharacterSize(35);
	label.setString("Score");
	label.setPosition({ 875.f, 100.f });
	label.setFillColor(sf::Color::White);

}

// This function is used to set the parameters for the win text, which appears on the screen after 5 batteries are collected.

void UI::WinLabel()
{

	win.setFont(fontage);
	win.setCharacterSize(35);
	win.setString("You Win");
	win.setPosition({ 875.f,400.f });
	win.setFillColor(sf::Color::White);

}

// This will draw the win message to the screen, when it is called in the Gameplay class.

void UI::WinDraw(sf::RenderWindow& window)
{

	window.draw(win);

}

// This function sets the parameters for the lose message, which appears on the screen if the snake head collides with the walls or snake body.

void UI::LoseLabel()
{

	lose.setFont(fontage);
	lose.setCharacterSize(35);
	lose.setString("You Lose");
	lose.setPosition({ 875.f,400.f });
	lose.setFillColor(sf::Color::White);

}

// This function draws the lose message to the screen, when it is called in the Gameplay class.

void UI::LoseDraw(sf::RenderWindow& window)
{

	window.draw(lose);

}

// This function draws the score and score labels to the screen.

void UI::UIDraw(sf::RenderWindow& window)
{

	window.draw(score);
	window.draw(label);
}