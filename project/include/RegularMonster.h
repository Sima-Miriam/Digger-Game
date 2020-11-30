#pragma once
#include"AMonster.h"

class RegularMonster:public AMonster
{
public:
	RegularMonster(const sf::Vector2f& location, const float height, const float width);
	virtual ~RegularMonster() = default;
	virtual void move(sf::Time) override;

protected:
	
};
