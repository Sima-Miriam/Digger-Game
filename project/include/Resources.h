#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

class Resources
{
public:
	std::vector<sf::Texture> m_imgs;
	~Resources() = default;
	static Resources& getInstance();
	sf::Font m_font;
	sf::Music m_music;
	sf::Music m_winSound;
	sf::Music m_failSound;

protected:
	Resources();
	Resources(const Resources& other) = default;
	Resources& operator=(const Resources& other) = default;
};
