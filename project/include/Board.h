#pragma once
#include "StaticObject.h"
#include <SFML/Graphics.hpp>
#include "Const.h"
#include <vector>
#include <fstream>
#include "Digger.h"
#include "Diamond.h"
#include "SmartMonster.h"
#include "Wall.h"
#include "Stone.h"
#include "RegularMonster.h"
#include "ScoreAddition.h"
#include "TimeAddition.h"
#include "StoneAddition.h"
#include <cstdlib>
#include "Resources.h"
class Level;
class Board
{
public:
	Board(Level&, Digger&, int numOfLevel);
	virtual ~Board();
	Board(const Board&) = delete;
	Board& operator=(const Board&) = delete;
	void initializeDataForLevel(Level&, Digger&);
	void draw(sf::RenderWindow&);
	StaticObject* getCell(const int i, const int j);
	bool isEmpty(sf::Vector2i cell);
	void deleteObject(sf::Vector2i cell);
	int getNumOfRows()const;
	int getNumOfCols()const;
	bool isWall(const sf::Vector2i&) const;
	bool isStone(const sf::Vector2i&) const;

protected:
	std::vector<std::vector<StaticObject*>> m_staticObjs;
	std::ifstream m_readFile;
	int m_rows;
	int m_cols;
	void setCharacter(const char&, const int, const float, const float, const sf::Vector2f, Level&, sf::Vector2f&, int&, Digger&);
	void addPresent(const int, const int, const int, const sf::Vector2f& location);


};
