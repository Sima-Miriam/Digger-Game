#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Const.h"

class Button
{
public:
	Button(const Objects index, const sf::Vector2f& location);
	virtual ~Button() = default;
	void draw(sf::RenderWindow& window)const;
	virtual void handleClick()const = 0;
	bool isContain(bool& isButtonPressed, const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window)const;


protected:
	sf::Sprite m_sprite;
};
