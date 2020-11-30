#pragma once
#include "DynamicObject.h"
#include "AMonster.h"

class Digger:public DynamicObject
{
public:
	Digger() ;
	~Digger() = default;
	void move(sf::Time deltaTime);
	void setDirection(sf::Keyboard::Key key);
	void decreaseDimonds();
	void addDiamondScore();
	void stopDigger();
	void decreaseStones();
	void decreaseLives();
	void addStone();
	void addScore();
	void addTime();
	sf::Vector2f getPosition() const;
	bool isColideWithMonster(AMonster& monster);
	int getLives() const;
	int getStones() const;
	int getScore() const;
	int getDiamonds() const;
	//void setTime(const int);
	int getTime();
	void setDigger(sf::Vector2f, const float, const float, const int, const int,const int);

protected:
	int m_lives;
	int m_stones;
	int m_score;
	int m_diamonds;
	Directions m_lastDirection;//for the diggers pictures
	sf::Vector2f m_futureDirection;
	Directions m_futurePicDirection;
	int m_futureIndex;
	int m_time;
	bool isSetDirectionPossible();

};
