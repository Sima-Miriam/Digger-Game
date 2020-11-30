#include"TimeAddition.h"

//c-tor
TimeAddition::TimeAddition(const sf::Vector2f& location, const float height, const float width) :
	Present(PrTime, location, height, width){}
//-------------------------------------------------------------------------------------------------
//colision with monster
void TimeAddition::colide(AMonster& monster){}
//-------------------------------------------------------------------------------------------------
//colision with digger
void TimeAddition::colide(Digger& digger)
{
	digger.addTime();
}
