#include "..\include\Level.h"


//--------------------------------------------------------------------------------------------------------------------------------
//c-tor
Level::Level(Digger& digger, int numOfLevel) :m_board(*this, digger, numOfLevel)
{
	Resources::getInstance().m_music.play();
}
//------------------------------------------------------------------------------------------------------------
//d-tor
Level::~Level()
{
	Resources::getInstance().m_music.stop();
}
//--------------------------------------------------------------------------------------------------------------------------------
//this function runs a single level
void Level::run(sf::RenderWindow& window, Digger& digger, bool& gameStatus, bool& restart, int numOfGame)
{
	while (window.isOpen())
	{
		window.clear();
		draw(window, digger);
		DisplayData::getInstance().displayData(digger.getLives(), digger.getScore(), digger.getStones(), numOfGame, digger.getTime() - (m_timeLeft.getElapsedTime().asSeconds()), window);
		window.display();
		auto deltaTime = m_clock.restart();
		handleEvent(window, digger);
		move(digger, deltaTime);
		colision(digger);
		if (digger.getStones() < 0 || digger.getTime() - (m_timeLeft.getElapsedTime().asSeconds()) <= 0)
		{
			digger.decreaseLives();
			restart = true;
		}
		if (digger.getLives() == 0)
			gameStatus = true;
		if (digger.getLives() == 0 || restart || digger.getDiamonds() == 0)
			return;
	}
}
//-------------------------------------------------------------------------------------------------------------------------------
//the function handles events from the user
void Level::handleEvent(sf::RenderWindow& window, Digger& digger)
{
	for (auto event = sf::Event{}; window.pollEvent(event);)
	{
		switch (event.type)
		{
		case sf::Event::Closed: //if the user closed the window
			window.close();
			exit(0);
			break;
		case sf::Event::KeyPressed:
			digger.setDirection(event.key.code);
		}
	}
}
//-------------------------------------------------------------------------------------------------------------------------------
//the function draws the level on the window
void Level::draw(sf::RenderWindow& window, Digger& digger)
{
	m_board.draw(window);
	printMonsters(window);
	digger.draw(window);
}
//-------------------------------------------------------------------------------------------------------------------------------
//the function draws the monsters on the window
void Level::printMonsters(sf::RenderWindow& window)
{
	for (auto monster : m_monsters)
		monster->draw(window);
}
//------------------------------------------------------------------------------------------------------------
//moves the objects
void Level::move(Digger& digger, sf::Time deltaTime)
{
	digger.move(deltaTime);
	moveMonsters(deltaTime);
}
//------------------------------------------------------------------------------------------------------------
//manages colision
void Level::colision(Digger& digger)
{
	auto cell = sf::Vector2i();
	cell = digger.getCell(m_board);
	if (cell != sf::Vector2i(-1, -1))//digger and static object
	{
		m_board.getCell(cell.y, cell.x)->colide(digger);
		if (!m_board.isWall(cell))
			m_board.deleteObject(cell);
	}
	for (auto monster : m_monsters)//monsters and static object
	{
		cell = monster->getCell(m_board);
		if (cell != sf::Vector2i(-1, -1))
			m_board.getCell(cell.y, cell.x)->colide(*monster);
	}
	for (auto monster : m_monsters)//digger and monsters
	{
		if (digger.isColideWithMonster(*monster))
		{
			for (auto monster : m_monsters)
				monster->resetPositions();
			break;
		}
	}
}
//------------------------------------------------------------------------------------------------------------------------------
//adds monsters to the matrix
void Level::addMonster(const float height, const float width, sf::Vector2f location, Digger& digger, Board& board)
{
	int typeOfMonster = rand() % TYPES_OF_MONSTERS;
	//int  typeOfMonster = RegularMonsterType;
	switch (typeOfMonster)//switch case on the type of monster that was chosen 
	{
	case SmartMonsterType:
		m_monsters.push_back(new (std::nothrow)SmartMonster(location, height, width, digger, board));
		break;
	case RegularMonsterType:
		m_monsters.push_back(new(std::nothrow)	RegularMonster(location, height, width));
		break;
	}
}
//----------------------------------------------------------------------------------------------------------
void Level::moveMonsters(sf::Time deltaTime)
{
	for (auto monster : m_monsters)
		monster->move(deltaTime);
}

