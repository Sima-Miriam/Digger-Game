#pragma once
#include "StaticObject.h"

class Stone:public StaticObject
{
public:
	Stone(const sf::Vector2f& location, const float height, const float width);
	virtual ~Stone() = default;
	virtual void colide(AMonster& monster)override;
	virtual void colide(Digger& digger)override;

protected:

};
