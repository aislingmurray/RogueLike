#include "Level.h"

Level::Level()
{
	levelWidth = 0;
	levelHeight = 0;
	level = nullptr;
}

void Level::loadLevel(int width, int height)
{
	//Sets the size of the console window and disables the mouse cursor
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.left, r.top, WINDOWSIZE_X, WINDOWSIZE_Y, TRUE); // window size in pixels
	utility::showConsoleCursor(FALSE);

	// define the size of the array
	levelWidth = width;
	levelHeight = height;

	// allocate memory for the 2D array
	level = new char[levelWidth * levelHeight];

	std::ifstream levelFile;

	levelFile.open("Level1.txt");

	if (!levelFile.is_open())
	{
		std::cout << "Unable to open file" << std::endl;
	}

	std::string line;
	utility::gotoScreenPosition(0, 0);
	while (getline(levelFile, line))
	{
		printLevel(line);
	}	
}

void Level::printLevel(std::string line) 
{
	std::cout << line << std::endl;
}

// Get the character at position xy on the map 
char Level::getXY(int x, int y) {
	return level[y * levelWidth + x];
}

// Set the character at position xy on the map 
bool Level::setXY(int x, int y, char value) {
	level[y * levelWidth + x] = value; //update value
	return true;
}

Level::~Level()
{
	delete[] level;
}