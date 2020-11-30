#pragma once
#include <SFML/Graphics.hpp>

const auto WIDTH_OF_WINDOW = 1280;
const auto HEIGHT_OF_WINDOW = 720;
const auto DIAMOND = 'D';
const auto MONSTER = '!';
const auto DIGGER = '/';
const auto STONE = '@';
const auto WALL = '#';
const auto PRESENT = '+';
const auto SPACE = ' ';
const auto LIVES = 3;
const auto BUTTON_HEIGHT = 107;
const auto BUTTON_WIDTH = 370;
const auto NEW_GAME_BUTTON_LOCATION = sf::Vector2f(460, 355);
const auto EXIT_BUTTON_LOCATION = sf::Vector2f(460, 475);
const auto TYPES_OF_MONSTERS = 2;
const auto TYPES_OF_PRESENTS = 3;
const auto MONSTERS_SPEED = 100;
const auto HEIGHT_OF_DATA_DISPLAY = 159;
const auto HEIGHT_OF_BOARD = 561;
const auto SPEED = 200;
const auto NUM_OF_DIGGER_PICTURES = 6;
const auto NUM_OF_MONSTER_PICTURES = 2;
const auto EPSILON = 1;
const auto LEFT = 71;
const auto RIGHT = 72;
const auto UP = 73;
const auto DOWN = 74;
const auto NUM_OF_STEPS = 400;
const auto NUM_OF_STEPS_SMART = 200;
const auto LEVEL = "Level";
const auto TIME_ADDITION = 5;
const auto DIAMOND_SCORE = 15;


enum Objects
{
	GameBoard, BackgroundDigger,BackGroundMenu, DiamondPic, StonePic, WallPic, PrStone, PrTime, PrScore,
	DiggerRightPic, DiggerLeftPic, DiggerUpRightPic, DiggerUpLeftPic, DiggerDownRightPic, DiggerDownLeftPic, SmartMonsterRightPic
	, SmartMonsterLeftPic, RegularMonsterRightPic, RegularMonsterLeftPic, NewGame, Exit, GameOver, Congratulations
};
enum Player 
{
	DiggerRight, DiggerLeft, DiggerUpRight, DiggerUpLeft, DiggerDownRight, DiggerDownLeft,
};
enum Monsters
{
	MonsterRight, MonsterLeft,
};
enum Directions
{
	Up, Down, Right, Left, Default,
};
enum Presents {
	TimePresent, StonePresent, ScorePresent
};
enum TypeOfMonsters {
	SmartMonsterType, RegularMonsterType
};
enum Music{
Town, Clap,};