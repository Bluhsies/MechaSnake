#include <SFML/Graphics.hpp>
#include <iostream>
#include"../include/Gameplay.h"

// Included above is the include file for Gameplay.h, which allows access to the Gameplay class, .h and .cpp files.

using namespace std;
using namespace sf;

// Below is the main function for the Snake game. This consists of an object made from the Gameplay class called 'game', which calls the function GameOn() to start the game. It will then return 0, once the game window has been closed.

int main()
{

	Gameplay game;

	game.GameOn();

	return 0;

}


/*
Reference List:

Haider, D. (2022) Snake_Logic.zip. De Montfort University. Available at: https://vle.dmu.ac.uk/webapps/blackboard/content/listContent.jsp?course_id=_600898_1&content_id=_5635443_1
Haider, D. (2022) Lecture materials for IMAT1908 weeks 1 - 11. De Montfort University. Available at: https://vle.dmu.ac.uk/webapps/blackboard/execute/announcement?method=search&context=course_entry&course_id=_600898_1&handle=announcements_entry&mode=view
Horton, J. (2019) Beginning C++ Game Programming. Packt Publishing Ltd. Birmingham. 2nd edition. 
SFML-Dev.org. (2022) Playing sounds and music. Accessed at: https://www.sfml-dev.org/tutorials/2.5/audio-sounds.php (Accessed on: 04/05/2022).

*/