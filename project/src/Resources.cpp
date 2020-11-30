#include"Resources.h"

Resources::Resources()
{
	//load pictures
	sf::Texture image;
	image.loadFromFile("GameBoarder.png");
	m_imgs.push_back(image);

	image.loadFromFile("BackGroundPlayer.png");
	m_imgs.push_back(image);

	image.loadFromFile("BackGround.png");
	m_imgs.push_back(image);

	image.loadFromFile("Diamond.png");
	m_imgs.push_back(image);

	image.loadFromFile("Stone.png");
	m_imgs.push_back(image);

	image.loadFromFile("Wall.png");
	m_imgs.push_back(image);

	image.loadFromFile("prStone.png");
	m_imgs.push_back(image);

	image.loadFromFile("prTime.png");
	m_imgs.push_back(image);

	image.loadFromFile("prScore.png");
	m_imgs.push_back(image);

	image.loadFromFile("PlayerRight.png");
	m_imgs.push_back(image);

	image.loadFromFile("PlayerLeft.png");
	m_imgs.push_back(image);

	image.loadFromFile("PlayerUpRight.png");
	m_imgs.push_back(image);

	image.loadFromFile("PlayerUpLeft.png");
	m_imgs.push_back(image);

	image.loadFromFile("PlayerDownRight.png");
	m_imgs.push_back(image);

	image.loadFromFile("PlayerDownLeft.png");
	m_imgs.push_back(image);

	image.loadFromFile("Mon1Right.png");
	m_imgs.push_back(image);

	image.loadFromFile("Mon1Left.png");
	m_imgs.push_back(image);

	image.loadFromFile("Mon2Right.png");
	m_imgs.push_back(image);

	image.loadFromFile("Mon2Left.png");
	m_imgs.push_back(image);

	image.loadFromFile("NewGame1.png");
	m_imgs.push_back(image);

	image.loadFromFile("EXIT.png");
	m_imgs.push_back(image);

	image.loadFromFile("gameOver.jpg");
	m_imgs.push_back(image);

	image.loadFromFile("winner.jpg");
	m_imgs.push_back(image);


	m_font.loadFromFile("c:/Windows/Fonts/Forte.ttf");//load texture
	m_music.openFromFile("town.wav");//load music
	m_failSound.openFromFile("fail.wav");
	m_winSound.openFromFile("clap.wav");
}
//------------------------------------------------------------------------------------------------------
//gets singltone
Resources& Resources::getInstance()
{
	static Resources m_instance;
	return m_instance;
}
