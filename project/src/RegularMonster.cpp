#include"RegularMonster.h"

//c-tor
RegularMonster::RegularMonster(const sf::Vector2f& location, const float height, const float width) :
	AMonster(RegularMonsterRightPic, location, height,width) {}
//-----------------------------------------------------------------------------------------------------------------
//moves the monsters
void  RegularMonster::move(sf::Time deltaTime)
{
	bool changedDirection = false;
	while (true)
	{
		if (m_numOfSteps == 0)
		{
			m_wantedDirection = Directions(rand() % 4);
			m_numOfSteps = NUM_OF_STEPS;
			changedDirection = true;
		}
		if (twist(m_wantedDirection) && checkDirection() || ((!twist(m_wantedDirection)) && changedDirection))
		{
			m_direction = convertDirection(m_wantedDirection);
			rotate(m_wantedDirection);
		}
		if (checkDestination(m_direction * deltaTime.asSeconds() + m_sprites[m_index].getPosition()))//our location is in the range our window
		{
			DynamicObject::move(deltaTime);
			m_numOfSteps--;
			return;
		}
		m_numOfSteps = 0;
	}
}
