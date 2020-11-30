#include"Button.h"

//c_tor
Button::Button(const Objects index, const sf::Vector2f& location) : m_sprite(Resources::getInstance().m_imgs[index])
{
	m_sprite.setPosition(location);

	auto txt = m_sprite.getTexture();
	auto texSize = txt->getSize();
	auto newTexSize = sf::Vector2u(BUTTON_WIDTH, BUTTON_HEIGHT);
	auto scaleX = newTexSize.x * 1.00f / texSize.x;
	auto scaleY = newTexSize.y * 1.00f / texSize.y;
	m_sprite.scale(scaleX, scaleY);
}
//---------------------------------------------------------------------------------------------------
//the function draws the button on the window
void Button::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}
//---------------------------------------------------------------------------------------------------
//the function checks if the user pressed the current button
bool Button::isContain(bool& isButtonPressed, const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window) const
{
	if (m_sprite.getGlobalBounds().contains(window.mapPixelToCoords({ event.x, event.y })))
	{
		isButtonPressed = true;
		return true;
	}
	return false;
}

