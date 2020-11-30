#include"AMonster.h"

//c-tor
AMonster::AMonster(const Objects index, const sf::Vector2f& location, const float height, const float width) :
DynamicObject(index,NUM_OF_MONSTER_PICTURES, location, height,width),m_numOfSteps(0), m_wantedDirection(Right){}
//---------------------------------------------------------------------------------------------------------------
//gets the monster global bounds
sf::FloatRect AMonster::getMonRec()
{
	return m_sprites[m_index].getGlobalBounds();
}
//---------------------------------------------------------------------------------------------------------------
//convert the direction from enum to vector
sf::Vector2f AMonster::convertDirection(const Directions direction) const
{
	switch (direction)
	{
	case Up:
		return sf::Vector2f(0, -MONSTERS_SPEED);
		break;
	case Down:
		return sf::Vector2f(0, MONSTERS_SPEED);
		break;
	case Left:
		return sf::Vector2f(-MONSTERS_SPEED, 0);
		break;
	case Right:
		return sf::Vector2f(MONSTERS_SPEED, 0);
		break;
	}
}
//--------------------------------------------------------------------------------------------------------------
//sets the picture
void AMonster::rotate(const Directions direction)
{
	if (direction == Right)
		m_index = MonsterRight;
	if (direction == Left)
		m_index = MonsterLeft;
}
//--------------------------------------------------------------------------------------------------------------
//the function checks if the monster turns
bool AMonster::twist(Directions m_wantdDirection)
{
	return (((m_wantdDirection == Right || m_wantdDirection == Left) && (m_direction == convertDirection(Up) || m_direction == convertDirection(Down)))

		|| (((m_wantdDirection == Up || m_wantdDirection == Down) && (m_direction == convertDirection(Right) || m_direction == convertDirection(Left)))));
}

