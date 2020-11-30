#pragma once
#include "Game.h"

class Controller
{
public:
	Controller();
	~Controller() = default;
	void run();

private:
	sf::RenderWindow m_window;
};
