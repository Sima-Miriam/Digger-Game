#pragma once
#include"Present.h"

class StoneAddition:public Present
{
public:
	StoneAddition(const sf::Vector2f& location, const float height, const float width);
	virtual ~StoneAddition() = default;
	virtual void colide(AMonster& monster)override;
	virtual void colide(Digger& digger)override;

protected:

};
