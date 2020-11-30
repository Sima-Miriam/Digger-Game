#pragma once
#include"Present.h"

class ScoreAddition:public Present
{
public:
	ScoreAddition(const sf::Vector2f& location, const float height, const float width);
	virtual ~ScoreAddition() = default;
	virtual void colide(AMonster& monster)override;
	virtual void colide(Digger& digger)override;

protected:

};
