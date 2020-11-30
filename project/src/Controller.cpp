#include "Controller.h"
//c-tor
Controller::Controller() : m_window(sf::VideoMode(WIDTH_OF_WINDOW, HEIGHT_OF_WINDOW), "DIGGER"){}
//-----------------------------------------------------------------------------------------------------------
//runs games till the user exit
void Controller::run()
{
	while (true)
	{
		Game game;
		game.run(m_window);
	}
}
