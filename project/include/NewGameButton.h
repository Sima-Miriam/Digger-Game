#pragma once
#include "Button.h"

class NewGameButton:public Button
{
public:
	NewGameButton(const sf::Vector2f& location);
	virtual ~NewGameButton() = default;
	virtual void handleClick()const override;

protected:

};
