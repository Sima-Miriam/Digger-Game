#pragma once
#include "StaticObject.h"

class Wall:public StaticObject
{
public:
	Wall(const sf::Vector2f& location, float height, float width);
	virtual ~Wall() = default;
	virtual void colide(AMonster& monster)override;
	virtual void colide(Digger& digger)override;

protected:

};
