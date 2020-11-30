#include "DynamicObject.h"
#include "Board.h"

//c-tor
DynamicObject::DynamicObject(const Objects StartIndex, const int EndIndex, const sf::Vector2f& location, const float height, const float width) :
m_startLocation(location), m_index(0), m_direction(0, 0), m_lastLocation(location)
{
	createVectorOfSprites(StartIndex, EndIndex, location, height, width);
}
//-------------------------------------------------------------------------------------------------------------
//checks the destination the dynamic object wants to go to
bool DynamicObject::checkDestination(const sf::Vector2f& destination)const
{
	return destination.y >= HEIGHT_OF_DATA_DISPLAY && destination.y + m_sprites[m_index].getGlobalBounds().height <= HEIGHT_OF_WINDOW && destination.x >= 0
		&& destination.x + m_sprites[m_index].getGlobalBounds().width <= WIDTH_OF_WINDOW;
}
//--------------------------------------------------------------------------------------------------------------
//updates the positions
void DynamicObject::updatePositions(const sf::Vector2f& destination)
{
	for (int i = 0; i < m_sprites.size(); i++)
		m_sprites[i].setPosition(destination);
}
//-----------------------------------------------------------------------------------------------------------
//get the direction from vector to enum
Directions DynamicObject::getDirection() const
{
	if (m_direction.x == 0 && m_direction.y == 0)
		return Default;
	else if (m_direction.x < 0)
		return Left;
	else if (m_direction.x > 0)
		return Right;
	else if (m_direction.y < 0)
		return Up;
	else if (m_direction.y > 0)
		return Down;
}
//----------------------------------------------------------------------------------------------------------
//revers to the object in case of wall or stone
void DynamicObject::rebackToLastPosition()
{
	for (int i = 0; i < m_sprites.size(); i++)
		m_sprites[i].setPosition(m_lastLocation);
}
//---------------------------------------------------------------------------------------------------
//gets the cell the object is on for the colision
sf::Vector2i DynamicObject::getCell(Board& board) const
{
	auto cell = sf::Vector2i(-1, -1);
	int width = m_sprites[m_index].getGlobalBounds().width;
	int height = m_sprites[m_index].getGlobalBounds().height;
	auto x = m_sprites[m_index].getPosition().x;
	auto y = m_sprites[m_index].getPosition().y;
	switch (getDirection())
	{
	case Up:
		cell = sf::Vector2i(floor((x+2) / width), floor((y - HEIGHT_OF_DATA_DISPLAY+2) / height));
		break;
	case Down:
		cell = sf::Vector2i(floor((x+2)/ width), (floor((y + height - HEIGHT_OF_DATA_DISPLAY-2) / height)));
		break;
	case Right:
		cell = sf::Vector2i(floor(((x + width-2 ) / width)), floor((y - HEIGHT_OF_DATA_DISPLAY+2) / height));
		break;
	case Left:
		cell = sf::Vector2i(floor((x+2) / width), floor((y - HEIGHT_OF_DATA_DISPLAY+2) / height));
		break;
	default:
		break;
	}
	//case the cell is empty, not in the limits or if the digger stops
	if (cell != sf::Vector2i(-1, -1) && cell.y < board.getNumOfRows() && cell.x < board.getNumOfCols())
	{
		if (!board.isEmpty(cell))
			return cell;
	}
	return cell = sf::Vector2i(-1, -1);
}
//---------------------------------------------------------------------------------------------------------
//checks if we can set the object direction and sets it by the axises
bool DynamicObject::checkDirection()
{
	auto newLocation = sf::Vector2f(-1, -1);
	auto width = m_sprites[m_index].getGlobalBounds().width;
	auto height = m_sprites[m_index].getGlobalBounds().height;
	auto x = m_sprites[m_index].getPosition().x;
	auto y = m_sprites[m_index].getPosition().y;
	switch (getDirection())//checks by the direction
	{
	case Right:
		if (std::abs(ceil((x + width) / width) * width -(x + width)) < EPSILON)
			newLocation = sf::Vector2f(ceil(((x + width) / width) * width) - width, y);
		break;
	case Left:
		if (std::abs(floor(x / width) * width- x) < EPSILON)
			newLocation = sf::Vector2f(floor(x / width) * width, y);
		break;
	case Up:
		if (std::abs((floor((y - HEIGHT_OF_DATA_DISPLAY) / height) * height) + HEIGHT_OF_DATA_DISPLAY- y) < EPSILON)
			newLocation = sf::Vector2f(x, floor((y - HEIGHT_OF_DATA_DISPLAY) / height) * height + HEIGHT_OF_DATA_DISPLAY);
		break;
	case Down:
		if (std::abs((ceil((y + height - HEIGHT_OF_DATA_DISPLAY) / height) * height) + HEIGHT_OF_DATA_DISPLAY- (y + height)) < EPSILON)
			newLocation = sf::Vector2f(x, std::abs((ceil((y + height - HEIGHT_OF_DATA_DISPLAY) / height) * height) + HEIGHT_OF_DATA_DISPLAY- height));
			break;
	}
		if (newLocation != sf::Vector2f(-1, -1))//if can set direction
		{
			if (!checkDestination(newLocation))
				return true;
			updatePositions(newLocation);
			return true;
		}
   return false;
}
//-------------------------------------------------------------------------------------------------------------
//takes the objects to their start location in the start of level
void DynamicObject::resetPositions()
{
	updatePositions(m_startLocation);
}
//------------------------------------------------------------------------------------------------------------
void DynamicObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprites[m_index]);
}
//-------------------------------------------------------------------------------------------------------------
//moves the objects
void DynamicObject::move(sf::Time deltaTime)
{
	m_lastLocation = m_sprites[m_index].getPosition();
	for (int i = 0; i < m_sprites.size(); i++)
		m_sprites[i].move(m_direction * deltaTime.asSeconds());
}
//-------------------------------------------------------------------------------------------------------------
//create the sprites for the object
void DynamicObject::createVectorOfSprites(const int startIndex, const int amount, const sf::Vector2f location, const float height, const float width)
{
	for (int index = startIndex; index < startIndex + amount; index++)
		m_sprites.push_back(createSprite(index, location, height, width));
}
