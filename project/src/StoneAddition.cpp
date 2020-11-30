#include"StoneAddition.h"

//c-tor
StoneAddition::StoneAddition(const sf::Vector2f& location, const float height, const float width) :
	Present(PrStone, location, height, width){}
//-------------------------------------------------------------------------------------------------
//colision with monster
void StoneAddition::colide(AMonster& monster){}
//-------------------------------------------------------------------------------------------------
//colision with digger
void StoneAddition::colide(Digger& digger)
{
	digger.addStone();
}
