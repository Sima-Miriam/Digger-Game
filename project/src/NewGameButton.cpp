#include "..\include\NewGameButton.h"
#include "NewGameButton.h"

//c-tor
NewGameButton::NewGameButton(const sf::Vector2f& location) : Button(NewGame, location){}
//---------------------------------------------------------------------------------------------------------------
//the function handles a mouse click on the new game buttons
void NewGameButton::handleClick() const{}
