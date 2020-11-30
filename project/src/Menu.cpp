#include "Menu.h"

//c-tor
Menu::Menu() : m_sprite(Resources::getInstance().m_imgs[BackGroundMenu])
{
	//creating the buttons 
	m_buttons.push_back(new(std::nothrow) NewGameButton(NEW_GAME_BUTTON_LOCATION));
	m_buttons.push_back(new(std::nothrow) ExitGameButton(EXIT_BUTTON_LOCATION));
}
Menu::~Menu()
{
	for (int i = 0; i < m_buttons.size(); i++)
		delete m_buttons[i];
}
//--------------------------------------------------------------------------------------------
//manages menu
void Menu::run(sf::RenderWindow& window)
{
	while (true)
	{
		if (auto event = sf::Event{}; window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::MouseButtonReleased:  //if the event was a mouse click
			{
				bool isButtonPressed = false;
				handleClick(isButtonPressed, event.mouseButton, window);
				if (isButtonPressed) //if the user pressed a button
					return;
				break;
			}
			case sf::Event::Closed: //if the user closed the window
				window.close();
				exit(0);
				break;
			}
		}
	}
}
//----------------------------------------------------------------------------------------------
//the function draws the menu on the window
void Menu::draw(sf::RenderWindow& window)const
{
	window.draw(m_sprite);
	for (Button* button : m_buttons)
		button->draw(window);
}
//----------------------------------------------------------------------------------------------
//the function handles a mouse click on the menu
void Menu::handleClick(bool& isButtonPressed, const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window)const
{
	for (Button* button : m_buttons)
		if(button->isContain(isButtonPressed, event, window))
			button->handleClick();
}
