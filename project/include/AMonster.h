#pragma once
#include "DynamicObject.h"

class AMonster :public DynamicObject
{
public:
	AMonster(const Objects index, const sf::Vector2f& location, const float height, const float width);
	virtual ~AMonster() = default;
	virtual void move(const sf::Time) = 0 {};
	sf::FloatRect getMonRec();


protected:
	sf::Vector2f convertDirection(const Directions)const;
	void rotate(const Directions);
	bool twist(Directions);
	int m_numOfSteps;
	Directions m_wantedDirection;
};

