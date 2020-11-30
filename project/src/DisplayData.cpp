#pragma once
#include "DisplayData.h"

//--------------------------------------------------------------------------------------------------------------------------------------------------
//displays the levels data
void DisplayData::displayData(const int lives, const int score, const int stones, const int level, const int time, sf::RenderWindow& window)
{

	m_lives.setString(std::to_string(lives));
	m_stones.setString(std::to_string(stones));
	m_score.setString(std::to_string(score));
	m_level.setString(std::to_string(level));
	window.draw(m_printLives);
	window.draw(m_lives);
	window.draw(m_printScore);
	window.draw(m_score);
	window.draw(m_printLevel);
	window.draw(m_level);
	window.draw(m_printStones);
	window.draw(m_stones);

	displayTime(time, window);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------
//singletone
DisplayData& DisplayData::getInstance()
{
	static  DisplayData m_instance;
	return m_instance;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------
//c-tor
DisplayData::DisplayData()
{
	m_printLives = sf::Text("LIVES:", Resources::getInstance().m_font);
	m_printLives.setPosition(0, 0);
	m_printLives.setColor(sf::Color::Black);
	m_lives.setPosition(m_printLives.getPosition().x + m_printLives.getGlobalBounds().width, 0);
	m_lives.setColor(sf::Color::Black);
	m_printScore = sf::Text("SCORE:", Resources::getInstance().m_font);
	m_printScore.setPosition(m_printLives.getPosition().x + m_printLives.getGlobalBounds().width + 100, 0);
	m_printScore.setColor(sf::Color::Black);
	m_score.setPosition(m_printScore.getPosition().x + m_printScore.getGlobalBounds().width, 0);
	m_score.setColor(sf::Color::Black);
	m_printStones = sf::Text("STONES:", Resources::getInstance().m_font);
	m_printStones.setPosition(m_printScore.getPosition().x + m_printScore.getGlobalBounds().width + 100, 0);
	m_printStones.setColor(sf::Color::Black);
	m_stones.setPosition(m_printStones.getPosition().x + m_printStones.getGlobalBounds().width, 0);
	m_stones.setColor(sf::Color::Black);
	m_printLevel = sf::Text("LEVEL:", Resources::getInstance().m_font);
	m_printLevel.setPosition(m_printStones.getPosition().x + m_printStones.getGlobalBounds().width + 100, 0);
	m_printLevel.setColor(sf::Color::Black);
	m_level.setPosition(m_printLevel.getPosition().x + m_printLevel.getGlobalBounds().width, 0);
	m_level.setColor(sf::Color::Black);
	m_level.setFont(Resources::getInstance().m_font);
	m_stones.setFont(Resources::getInstance().m_font);
	m_score.setFont(Resources::getInstance().m_font);
	m_lives.setFont(Resources::getInstance().m_font);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
//displays the time
void DisplayData::displayTime(const int seconds, sf::RenderWindow& window)
{

	auto txt = sf::Text();
	auto color = sf::Color();
	if (seconds / 5 < 1)
		color = sf::Color::Red;
	else
		color = sf::Color::Black;

	if (seconds / 60 >= 10 && seconds % 60 >= 10)//in case we don't have to add zeros
		txt = sf::Text(std::to_string(seconds / 60) + ":" + std::to_string(seconds % 60), Resources::getInstance().m_font);
	else  if (seconds / 60 < 10 && seconds % 60 >= 10)//we have to add a zero to the mintues
		txt = sf::Text(std::to_string(0) + std::to_string(seconds / 60) + ":" + std::to_string(seconds % 60), Resources::getInstance().m_font);
	else   if (seconds / 60 >= 10 && seconds % 60 < 10)//we have to add a zero to the seconds
		txt = sf::Text(std::to_string(seconds / 60) + ":" + std::to_string(0) + std::to_string(seconds % 60), Resources::getInstance().m_font);
	else//we have to add a zero to the minutes and to the seconds
		txt = sf::Text(std::to_string(0) + std::to_string(seconds / 60) + ":" + std::to_string(0) + std::to_string(seconds % 60), Resources::getInstance().m_font);
	txt.setCharacterSize(70);
	txt.setColor(color);
	txt.setPosition(WIDTH_OF_WINDOW - 250, 0);
	window.draw(txt);
}
