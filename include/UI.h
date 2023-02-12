#pragma once

// This is the UI class, which has all of the necessary functions available to create the UI for Snake.
// Included is the SFML/Graphics.hpp, which allows for the creating, rendering and drawing of the shapes, sprites and textures associated with the game.

#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace std;

class UI
{

private:

	// The below variables are used to initiate the font and text for the score, score label, win and lose texts to the screen.

	sf::Font fontage;
	sf::Text score;
	sf::Text label;
	sf::Text win;
	sf::Text lose;

public:

	// The constructor UI(); has been set as a public function, so that the other functions can access the data stored within, such as the ability to fonts.

	UI();

	// The below function allows for the score's text, position, character size and fill colour to be set.

	void settingsUI();

	// The below function allows for the score and score label to be drawn to the screen.

	void UIDraw(sf::RenderWindow& window);

	// The below function allows for the MechaSnakeScore in the Gameplay class to be increased by 1 each time a battery is collected.

	void UIScoreText(const std::string& text);

	// The below function allows for the text, position, character size, fill colour and string to be set for the score label.

	void UIScoreLabel();

	// The below function allows for the text, position, character size, fill colour and string to be set for the win label.

	void WinLabel();

	// The below function allows for the text, position, character size, fill colour and string to be set for the lose label.

	void LoseLabel();

	// The below function allows for the lose message to be printed to the screen. This is separate to the WinDraw function, so that both messages are not printed to the screen and to keep them separate from one another.

	void LoseDraw(sf::RenderWindow& window);

	void WinDraw(sf::RenderWindow& window);



};