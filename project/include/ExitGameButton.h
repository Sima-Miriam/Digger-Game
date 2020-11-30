#pragma once
#include"Button.h"


class ExitGameButton :public Button
{
public:
	ExitGameButton(const sf::Vector2f& location);
	virtual ~ExitGameButton() = default;
	virtual void handleClick()const override;
protected:

};
