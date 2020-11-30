#include"Game.h"

//c-tor
Game::Game() : m_digger() {}
//--------------------------------------------------------------------------------------------------------
//runs a game
void Game::run(sf::RenderWindow& window)
{
	while (window.isOpen())
	{
		managesMenu(window);
		bool gameStatus = false;
		managesLevels(window, gameStatus);
		managesEndOfGame(window, gameStatus);
		return;
	}
}
//-------------------------------------------------------------------------------------------------------
//presents the menu
void Game::managesMenu(sf::RenderWindow& window)
{
	window.clear();
	m_menu.draw(window);
	window.display();
	m_menu.run(window);
}
//-------------------------------------------------------------------------------------------------------
//runs the levels 
void Game::managesLevels(sf::RenderWindow& window, bool& gameStatus)
{
	std::string level = "Level";
	int numOfLevel = 1;
	while (std::ifstream(level + std::to_string(numOfLevel) + ".txt"))
	{
		bool restart = false;
		Level level(m_digger, numOfLevel);
		level.run(window, m_digger, gameStatus, restart, numOfLevel);
		if (restart)//if the level should be restarted
			numOfLevel--;
		numOfLevel++;
		if (gameStatus)
			return;
	}
}
//------------------------------------------------------------------------------------------------------
//display the end of the game
void Game::managesEndOfGame(sf::RenderWindow& window, bool& gameStatus)
{
	if (gameStatus)//play ending music
		Resources::getInstance().m_failSound.play();
	else
		Resources::getInstance().m_winSound.play();
	while (window.isOpen())//presents ending picture
	{
		auto sprite = sf::Sprite();
		if (gameStatus)
			sprite = sf::Sprite(Resources::getInstance().m_imgs[GameOver]);
		else
			sprite = sf::Sprite(Resources::getInstance().m_imgs[Congratulations]);
		window.draw(sprite);
		window.display();
		if (auto event = sf::Event{}; window.pollEvent(event))
			if (event.type == sf::Event::Closed)
			{
				if (gameStatus)
					Resources::getInstance().m_failSound.stop();
				else
					Resources::getInstance().m_winSound.stop();
			return;
			}
	}
}

