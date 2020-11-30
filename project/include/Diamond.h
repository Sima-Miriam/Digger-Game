#pragma once
#include "StaticObject.h"

class Diamond:public StaticObject
{
public:
	Diamond(const sf::Vector2f& location, float height, float width);
	virtual ~Diamond() = default;
	virtual void colide(AMonster& monster)override;
	virtual void colide(Digger& digger)override;
protected:

};
