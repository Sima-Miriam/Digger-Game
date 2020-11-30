#pragma once
#include "Level.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include "Const.h"
#include "Resources.h"
#include <fstream>


class Game
{
public:
	Game();
	~Game() = default;
	void run(sf::RenderWindow&);

protected:
	Menu m_menu;
	Digger m_digger;
	void managesMenu(sf::RenderWindow& window);
	void managesLevels(sf::RenderWindow& window, bool& gameStatus);
	void managesEndOfGame(sf::RenderWindow& window, bool& gameStatus);
};
