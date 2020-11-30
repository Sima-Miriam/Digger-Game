#include"Diamond.h"

//c-tor
Diamond::Diamond(const sf::Vector2f& location, float height, float width) :
StaticObject(DiamondPic, location, height, width){}
//-------------------------------------------------------------------------------------------------------
//colide with monster
void Diamond::colide(AMonster& monster){}
//-------------------------------------------------------------------------------------------------------
//colide with digger
void Diamond::colide(Digger& digger)
{
	digger.addDiamondScore();
	digger.decreaseDimonds();
}
