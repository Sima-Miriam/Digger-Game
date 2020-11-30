#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Const.h"

class DisplayData
{
public:
	void displayData(const int, const int, const int, const int, const int, sf::RenderWindow&);
	~DisplayData() = default;
	static DisplayData& getInstance();
protected:
	sf::Text m_printLives;
	sf::Text m_printStones;
	sf::Text m_printScore;
	sf::Text m_printLevel;
	sf::Text m_lives;
	sf::Text m_stones;
	sf::Text m_score;
	sf::Text m_level;
	DisplayData();
	DisplayData(const DisplayData& other) = default;
	DisplayData& operator=(const DisplayData& other) = default;
	void displayTime(const int, sf::RenderWindow&);

};