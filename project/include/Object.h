#pragma once
#include <SFML/Graphics.hpp>
#include "Const.h"
#include "Resources.h"

class Object
{
public:
	Object() = default;
	~Object() = default;
	sf::Sprite createSprite(const int index, const sf::Vector2f& location,const float height,const float width);

protected:
};