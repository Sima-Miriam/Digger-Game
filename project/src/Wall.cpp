#include"Wall.h"

//c-tor
Wall::Wall(const sf::Vector2f& location,float height,float width) :
	StaticObject(WallPic, location, height, width){}
//-------------------------------------------------------------------------------------------------
//colision with monster
void Wall::colide(AMonster& monster)
{
	monster.rebackToLastPosition();
}
//-------------------------------------------------------------------------------------------------
//colision with digger
void Wall::colide(Digger& digger)
{
	digger.rebackToLastPosition();
	digger.stopDigger();
}
