#include"Stone.h"

//c-tor
Stone::Stone(const sf::Vector2f& location, const float height, const float width) :
	StaticObject(StonePic, location, height, width){}
//-------------------------------------------------------------------------------------------------
//colision with monster
void Stone::colide(AMonster& monster)
{
	monster.rebackToLastPosition();
}
//-------------------------------------------------------------------------------------------------
//colision with digger
void Stone::colide(Digger& digger)
{
	digger.decreaseStones();
}
