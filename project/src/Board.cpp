
#include "Board.h"
#include "Level.h"

//-----------------------------------------------------------------------------------------------------------------------------------------
//c-tor
Board::Board(Level& level, Digger& digger, int numOfLevel) : m_readFile(std::ifstream(LEVEL + std::to_string(numOfLevel) + ".txt")),
 m_rows(0), m_cols(0)
{
	initializeDataForLevel(level, digger);
}
//-----------------------------------------------------------------------------------------------------------------------------------------
//d-tor
Board::~Board()
{
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_cols; j++)
			delete m_staticObjs[i][j];
}
//----------------------------------------------------------------------------------------------------------------------------------------
//reads the data from the file
void Board::initializeDataForLevel(Level& level, Digger& digger)
{
	int  numStones, diamonds = 0,seconds;
	float widthObject, heightObject, numRows, numCols;
	m_readFile >> numRows >> numCols >> numStones>>seconds;
	m_rows = numRows;
	m_cols = numCols;
	sf::Vector2f  playersLocation;
	//calculating the right width and row of each object(his picture) according to the width/height of the window and amount of row/cols
	widthObject = WIDTH_OF_WINDOW / numCols;
	heightObject = HEIGHT_OF_BOARD / numRows;
	std::string line;
	srand(time(0));
	getline(m_readFile, line);//for the endl character that comes after the number of stones
	for (int row = 0; row < numRows; row++)
	{
		line.clear();
		getline(m_readFile, line);//the next line of the file
		std::vector<StaticObject*> lineStatic;
		m_staticObjs.push_back(lineStatic);//pushing a line of staticObject* and will replace them with the right objects when reading the line

		for (int col = 0; col < line.size(); col++)
		{
			sf::Vector2f location(col * widthObject, row * heightObject + HEIGHT_OF_DATA_DISPLAY);//calculation the location of the object on the window			//setCharacter(line[col], row, heightObject, widthObject, location, level, digger, numStones, resource);//sending to a function
			setCharacter(line[col], row, heightObject, widthObject, location, level, playersLocation, diamonds, digger);
		}
	}
	digger .setDigger(playersLocation, heightObject, widthObject, diamonds, numStones,seconds);//set the digger

}
//---------------------------------------------------------------------------------------------------------------------------
//draw the board on the window
void Board::draw(sf::RenderWindow& window)
{
	auto image = Resources::getInstance().m_imgs[GameBoard];
	sf::Sprite m_sprite;
	m_sprite.setTexture(image);

	window.draw(m_sprite);
	for (int row = 0; row < m_staticObjs.size(); row++)
		for (int col = 0; col < m_staticObjs[row].size(); col++)
			if (m_staticObjs[row][col] != NULL)
				m_staticObjs[row][col]->draw(window);
}
//---------------------------------------------------------------------------------------------------------------------------
//returns the cell from the board
StaticObject* Board::getCell(const int i, const int j)
{
	return m_staticObjs[i][j];
}
//---------------------------------------------------------------------------------------------------------------------------
//checks if the cell is empty
bool Board::isEmpty(sf::Vector2i cell)
{
	if (m_staticObjs[cell.y][cell.x] == nullptr)
		return true;
	return false;
}
//----------------------------------------------------------------------------------------------------------------------------
//remove the eaten object from the board
void Board::deleteObject(sf::Vector2i cell)
{
	delete m_staticObjs[cell.y][cell.x];
	m_staticObjs[cell.y][cell.x] = nullptr;
}
//-----------------------------------------------------------------------------------------------------------------------------
//returns number of rows 
int Board::getNumOfRows() const
{
	return m_rows;
}
//-----------------------------------------------------------------------------------------------------------------------------
//returns number of cols
int Board::getNumOfCols() const
{
	return m_cols;
}
//-----------------------------------------------------------------------------------------------------------------------------
//checks if the object is wall
bool Board::isWall(const sf::Vector2i& location) const
{
	return (typeid(Wall).name() == typeid(*m_staticObjs[location.y][location.x]).name());
}
//-----------------------------------------------------------------------------------------------------------------------------
//checks if the object is stone
bool Board::isStone(const sf::Vector2i& location) const
{
	return(typeid(Stone).name() == typeid(*m_staticObjs[location.y][location.x]).name());
}

//-------------------------------------------------------------------------------------------------------------------------------
//checks what character it is and adds it to the matrix
void Board::setCharacter(const char& characterInFile, const int row, const float heightObject, const float widthObject, const sf::Vector2f location, Level& level, sf::Vector2f& playersLocation, int& diamonds, Digger& digger)
{
	switch (characterInFile) {//switch case on the character found in the file and building the right object.... 
	case DIAMOND:
		m_staticObjs[row].push_back(new(std::nothrow) Diamond(location, heightObject, widthObject));
		diamonds++;
		break;
	case DIGGER:
		playersLocation = location;
		m_staticObjs[row].push_back(nullptr);
		break;
	case STONE:
		m_staticObjs[row].push_back(new(std::nothrow) Stone(location, heightObject, widthObject));
		break;
	case WALL:
		m_staticObjs[row].push_back(new(std::nothrow) Wall(location, heightObject, widthObject));
		break;
	case SPACE:
		m_staticObjs[row].push_back(nullptr);
		break;
	case PRESENT:
		addPresent(row, heightObject, widthObject, location);
		break;
	case MONSTER:
		level.addMonster(heightObject, widthObject, location, digger,*this);//sending to a function in the level to add a monster to the vector
		m_staticObjs[row].push_back(nullptr);
		break;
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------
//adds present to the matrix
void Board::addPresent(const int row, const int heightObject, const int widthObject, const sf::Vector2f& location)
{

	int typeOfPresent = rand() % TYPES_OF_PRESENTS;//choosing a random number between 0 and the number of types of presents we have
	//and according to the result we will add the right type of presents(each present has a enum number declared in the consts.h file 
	//according to the enum we will build the right present)
	switch (typeOfPresent)//switch case on the type of present that was chosen-building the right present and adding it to the vector
	{
	case TimePresent:
		m_staticObjs[row].push_back(new(std::nothrow)	TimeAddition(location, heightObject, widthObject));
		break;
	case StonePresent:
		m_staticObjs[row].push_back(new(std::nothrow)	StoneAddition(location, heightObject, widthObject));
		break;
	case ScorePresent:
		m_staticObjs[row].push_back(new(std::nothrow)	ScoreAddition(location, heightObject, widthObject));
		break;
	}
}

