#include "StaticObject.h"

//c-tor
StaticObject::StaticObject(const Objects index, const sf::Vector2f& location,const float height,float width) :
	m_sprite(createSprite(index, location, height, width)){}

void StaticObject::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}