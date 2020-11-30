#pragma once
#include "Object.h"

class Board;
class DynamicObject:public Object
{
public:
	DynamicObject() = default;
	DynamicObject(const Objects StartIndex, const int EndtIndex, const sf::Vector2f& location,const float height,const float width);
	~DynamicObject() = default;
	bool checkDestination(const sf::Vector2f& destination) const;
	void updatePositions(const sf::Vector2f& destination);
	Directions getDirection()const;
	void rebackToLastPosition();
	sf::Vector2i getCell(Board& board) const;
	bool checkDirection();
	void resetPositions();
	void draw(sf::RenderWindow& window)const;
	void createVectorOfSprites(const int startIndex, const int amount, const sf::Vector2f location, const float height, const float width);


protected:
	std::vector<sf::Sprite> m_sprites;
	sf::Vector2f m_startLocation;
	int m_index;
	sf::Vector2f m_direction;
	sf::Vector2f m_lastLocation;
	void move(sf::Time deltaTime);
};
