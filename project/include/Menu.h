#pragma once
//#include "Button.h"
#include <vector>
#include "ExitGameButton.h"
#include "NewGameButton.h"
#include "Const.h"

class Menu
{
public:
	Menu();
	~Menu();
	Menu(const Menu&) = delete;
	Menu& operator=(const Menu&) = delete;
	void run(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window)const;
	void handleClick(bool& isButtonPressed, const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window)const;

protected:
	sf::Sprite m_sprite;
	std::vector <Button*> m_buttons;
};
