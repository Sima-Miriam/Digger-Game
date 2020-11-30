#include"ScoreAddition.h"

//c-tor
ScoreAddition::ScoreAddition(const sf::Vector2f& location, const float height, const float width) :
	Present(PrScore, location, height, width){}

//-------------------------------------------------------------------------------------------------
//colision with monster
void ScoreAddition::colide(AMonster& monster){}
//-------------------------------------------------------------------------------------------------
//colision with digger
void ScoreAddition::colide(Digger& digger)
{
	digger.addScore();
}
