#pragma once
#include "Object.h"
#include "Digger.h"
#include "AMonster.h"

class StaticObject:public Object
{
public:
	StaticObject(const Objects index, const sf::Vector2f& location,float height,float width);
	virtual ~StaticObject() = default;
	void draw(sf::RenderWindow& window);
	virtual void colide(AMonster& monster) = 0;
	virtual void colide(Digger& digger) = 0;

protected:
	sf::Sprite m_sprite;
};

