#include"Digger.h"

//c-tor
Digger::Digger()
	: m_lives(LIVES), m_score(0)
{}
//-------------------------------------------------------------------------------------------------------------------------
//gets the event from the user and sets the direction according to that
void Digger::setDirection(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Space:
		m_futureDirection = sf::Vector2f(0, 0);
		break;
	case sf::Keyboard::Left:
		m_futureDirection = sf::Vector2f(-SPEED, 0);
		m_futureIndex = DiggerLeft;
		m_futurePicDirection = Left;
		break;
	case sf::Keyboard::Right:
		m_futureDirection = sf::Vector2f(SPEED, 0);
		m_futureIndex = DiggerRight;
		m_futurePicDirection = Right;
		break;
	case sf::Keyboard::Up:
		m_futureDirection = sf::Vector2f(0, -SPEED);
		(m_lastDirection == Left) ? m_futureIndex = DiggerUpLeft : m_futureIndex = DiggerUpRight;
		break;
	case sf::Keyboard::Down:
		m_futureDirection = sf::Vector2f(0, SPEED);
		(m_lastDirection == Left) ? m_futureIndex = DiggerDownLeft : m_futureIndex = DiggerDownRight;
		break;
	}
}
//---------------------------------------------------------------------------------------------------------------
//the function returns true if setting direction is possible
bool Digger::isSetDirectionPossible()
{
	if (((getDirection() == Up || getDirection() == Down) && (m_futureDirection == sf::Vector2f(SPEED, 0) || m_futureDirection == sf::Vector2f(-SPEED, 0) || m_futureDirection == sf::Vector2f(0, 0))) ||
		((getDirection() == Right || getDirection() == Left) && (m_futureDirection == sf::Vector2f(0, -SPEED) || m_futureDirection == sf::Vector2f(0, SPEED) || m_futureDirection == sf::Vector2f(0, 0))))
		if (checkDirection())
			return true;
		else
			return false;
	return true;
}
//-------------------------------------------------------------------------------------------------------------------
//moves the digger
void Digger::move(sf::Time deltaTime)
{
	if (isSetDirectionPossible())
	{
		m_direction = m_futureDirection;
		m_index = m_futureIndex;
		m_lastDirection = m_futurePicDirection;
	}
	if (checkDestination(m_direction * deltaTime.asSeconds() + m_sprites[m_index].getPosition()))
		DynamicObject::move(deltaTime);
}
//------------------------------------------------------------------------------------------------------------
//decrease diomaond
void Digger::decreaseDimonds()
{
	m_diamonds--;
}
//---------------------------------------------------------------------------------------------------------------
//adds score for diamond
void Digger::addDiamondScore()
{
	m_score += DIAMOND_SCORE;
}
//----------------------------------------------------------------------------------------------------------------
//stops the digger
void Digger::stopDigger()
{
	m_direction = sf::Vector2f(0, 0);
}
//----------------------------------------------------------------------------------------------------------------
//decrease stones
void Digger::decreaseStones()
{
	m_stones--;
}
//----------------------------------------------------------------------------------------------------------------
//decrease lives
void Digger::decreaseLives()
{
	m_lives--;
}
//----------------------------------------------------------------------------------------------------------------
//adds stone
void Digger::addStone()
{
	m_stones++;
}
//----------------------------------------------------------------------------------------------------------------
//adds score
void Digger::addScore()
{
	m_score += 20;
}
//----------------------------------------------------------------------------------------------------------------
//adds time
void Digger::addTime()
{
	m_time += TIME_ADDITION;
}
//----------------------------------------------------------------------------------------------------------------
//gets the digger position for the monster
sf::Vector2f Digger::getPosition() const
{
	return m_sprites[m_index].getPosition();
}
//----------------------------------------------------------------------------------------------------------------
//checkd if the digger colides with a monster
bool Digger::isColideWithMonster(AMonster& monster)
{
	if (m_sprites[m_index].getGlobalBounds().intersects(monster.getMonRec()))
	{
		resetPositions();
		m_lives--;
		return true;
	}
	return false;
}
//------------------------------------------------------------------------------------------------------------
//returns the diggers live
int  Digger::getLives() const
{
	return m_lives;
}
//------------------------------------------------------------------------------------------------------------
//returns the diggers stone
int Digger::getStones() const
{
	return m_stones;
}
//------------------------------------------------------------------------------------------------------------
//returns the diggers score
int Digger::getScore() const
{
	return m_score;
}
//------------------------------------------------------------------------------------------------------------
//returns the diggers diamonds
int Digger::getDiamonds() const
{
	return m_diamonds;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//gets the digger time
int Digger::getTime()
{
	return m_time;
}
//-----------------------------------------------------------------------------------------------------------------
//sets the digger data
void Digger::setDigger(sf::Vector2f location, const float height, const float width, const int diamonds, const int stones,const int seconds)
{
	m_sprites.clear();
	m_time = seconds;
	m_startLocation = location;
	m_diamonds = diamonds;
	m_stones = stones;
	m_startLocation = m_lastLocation = location;
	m_futurePicDirection = Right;
	m_index = 0;
	m_lastDirection = Right;
	m_futureIndex = 0;
	m_futureDirection = sf::Vector2f(0, 0);
	createVectorOfSprites(DiggerRightPic, NUM_OF_DIGGER_PICTURES, location, height, width);
}


