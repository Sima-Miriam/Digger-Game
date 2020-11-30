#pragma once
#include "Board.h"
#include "Digger.h"
#include "RegularMonster.h"
#include "SmartMonster.h"
#include <vector>
#include "DisplayData.h"
#include <SFML/Audio.hpp>
class Level
{
public:
	void addMonster(const float, const float, sf::Vector2f, Digger&,Board&);
	Level(Digger&, int numOfLevel);
	~Level();
	Level(const Level&) = delete;
	Level& operator=(const Level&) = delete;
	void run(sf::RenderWindow&, Digger&, bool& gameStatus, bool& restart, int numOfGame);
	void handleEvent(sf::RenderWindow&, Digger&);
	void draw(sf::RenderWindow&, Digger&);
	void printMonsters(sf::RenderWindow&);
	void move(Digger& digger, sf::Time deltaTime);
	void colision(Digger&);

protected:
	std::vector<AMonster*> m_monsters;
	Board m_board;
	sf::Clock m_clock;
	sf::Clock m_timeLeft;
	void moveMonsters(sf::Time);

};
 
