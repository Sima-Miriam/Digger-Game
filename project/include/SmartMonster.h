#pragma once
#include"AMonster.h"
#include "Digger.h"

class Board;
class SmartMonster:public AMonster
{
public:
	SmartMonster(const sf::Vector2f& location, const float height, const float width, Digger&,Board&);
	virtual ~SmartMonster() = default;
	virtual void move(sf::Time) override;

protected:
	Digger& m_digger;
	Board& m_board;
	bool  checkObstacle(sf::Vector2f& destination);
	void changeDirection();

};
