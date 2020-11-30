#pragma once
#include"Present.h"

class TimeAddition:public Present
{
public:
	TimeAddition(const sf::Vector2f& location, const float height, const float width);
	virtual ~TimeAddition() = default;
	virtual void colide(AMonster& monster)override;
	virtual void colide(Digger& digger)override;

protected:

};
