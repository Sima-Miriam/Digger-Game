#pragma once
#include "StaticObject.h"

class Present:public StaticObject
{
public:
	Present(const Objects index, const sf::Vector2f& location,const float height,const float width);
	virtual ~Present() = default;
	virtual void colide(AMonster& monster) = 0;
	virtual void colide(Digger& digger) = 0;

protected:

};
