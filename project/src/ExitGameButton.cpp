#include "ExitGameButton.h"

//c_tor
ExitGameButton::ExitGameButton(const sf::Vector2f& location) : Button(Exit, location){}
//-------------------------------------------------------------------------------------------------------
//the function handles a mouse click on the exit buttons
void ExitGameButton::handleClick() const
{
	exit(0);
}
