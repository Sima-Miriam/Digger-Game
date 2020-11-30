#include "Object.h"
//--------------------------------------------------------------------------------------------------------------------
//creates the sprite for the object
sf::Sprite Object::createSprite(const int index, const sf::Vector2f& location, const float height, const float width)
{
	auto sprite = sf::Sprite(Resources::getInstance().m_imgs[index]);
	sprite.setPosition(location);

	auto txt = sprite.getTexture();
	auto texSize = txt->getSize();
	auto newTexSize = sf::Vector2f(width, height);
	auto scaleX = newTexSize.x * 1.00f / texSize.x;
	auto scaleY = newTexSize.y * 1.00f / texSize.y;
	sprite.setScale(scaleX, scaleY);

	return sprite;
}



