#include "SmartMonster.h"
#include "Board.h"

//c-tor
SmartMonster::SmartMonster(const sf::Vector2f& location, const float height, const float width, Digger& digger, Board& board)
	:AMonster(SmartMonsterRightPic, location, height, width), m_digger(digger), m_board(board) {}

//-------------------------------------------------------------------------------------------------------------
void SmartMonster::move(sf::Time deltaTime)
{
		if (m_numOfSteps != 0)//the monster got stuck so he will continue going in the same direction so he should get released
		{
			if (checkDestination(m_direction * deltaTime.asSeconds() + m_sprites[m_index].getPosition()))
			{
				m_numOfSteps--;
				DynamicObject::move(deltaTime);
				return;
			}
			else
				m_numOfSteps = 0;//in case he's stuck in the edge of the window
		}
	auto minDistance = std::max(std::pow(WIDTH_OF_WINDOW,2), std::pow(HEIGHT_OF_WINDOW, 2));
	float distance;
	sf::Vector2f direction, destination, minDestination, minDirection;
	for (int index = 0; index < 4; index++)//going through the 4 possible directions
	{
		direction = convertDirection(Directions(index));
		destination = direction*deltaTime.asSeconds() + m_sprites[m_index].getPosition();//destination in case of moving to the "index" direction
		distance = std::abs(m_digger.getPosition().x - destination.x) + std::abs(m_digger.getPosition().y - destination.y);//distance from the destination to the digger
		if (distance < minDistance && checkDestination(destination))//if the distance is smaller than minDistance and the destination is in the range of our window
		{
			minDistance = distance;
			m_wantedDirection = Directions(index);
		}
	}
	if (checkObstacle(destination))//if we won't get stuck in case of moving to this destination
		if (((twist(m_wantedDirection) && checkDirection()) || !twist(m_wantedDirection)))//checking if the move is allowed at this point-in case of twisting
		{
			m_direction= convertDirection(m_wantedDirection);
			rotate(m_wantedDirection);
		}
	DynamicObject::move(deltaTime);
}

//-----------------------------------------------------------------------------------------------------------------------
//checks if there is in front of the monster wall or stone
bool  SmartMonster::checkObstacle(sf::Vector2f& destination)
{
	//saving the position and direction because the function getCell works on the wantedDirection
	//and position
	sf::Vector2f position = m_sprites[m_index].getPosition(), myDirection = m_direction;
	//changing the direction and position for getCell
	m_direction = convertDirection(Directions(m_wantedDirection));
	m_sprites[m_index].setPosition(destination);
	sf::Vector2i cell = getCell(m_board);
	if (cell == sf::Vector2i{ -1,-1 } || (!(m_board.isStone(cell))&&!(m_board.isWall(cell))))//if cell the monster wants to move
		//to isn't a stone or a wall(-1,-1)indicates that the cell is empty
	{
		m_direction = myDirection;
		m_sprites[m_index].setPosition(position);
		return true;
	}
	else//monster is stuck
	{
		changeDirection();
		m_numOfSteps = NUM_OF_STEPS_SMART;
		m_sprites[m_index].setPosition(position);
		return false;
	}
	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
//sets the monster direction
void SmartMonster::changeDirection()
{
	//this function changes the SmartMonsters direction in case he got stuck in a stone or wall
	switch (m_wantedDirection)
	{
	case Left:
	case Right:
		m_direction = convertDirection(Directions(rand() % 2));
		break;
	case Up:
	case Down:
		m_direction= convertDirection(Directions(rand() % 2 + 2));
		break;
	}
}
