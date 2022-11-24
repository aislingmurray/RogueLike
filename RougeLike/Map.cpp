#include "Map.h"

Map::Map()
{
	mapWidth = 0;
	mapHeight = 0;
	map = nullptr;
}

void Map::loadMap(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.left, r.top, WINDOWSIZE_X, WINDOWSIZE_Y, TRUE); // window size in pixels
	utility::showConsoleCursor(FALSE);


	// define the size of the array
	mapWidth = width;
	mapHeight = height;

	// allocate memory for the 2D array
	map = new char[mapWidth * mapHeight];

	// For now just create a map with walls. Later we implement reading from file
	for (int y = 0; y < mapHeight; y++)
	{
		for (int x = 0; x < mapWidth; x++)
		{
			if (x == 0 || x == mapWidth - 1 || y == 0 || y == mapHeight - 1)
				map[y * mapWidth + x] = WALLCHAR;
			else
				map[y * mapWidth + x] = FLOORCHAR;
		}
	}

	printMap();
}

void Map::printMap() {

	utility::goToScreenPosition(0, 0);
	for (int y = 0; y < mapHeight; y++)
	{
		for (int x = 0; x < mapWidth; x++)
		{
			std::cout << map[y * mapWidth + x];
		}
		std::cout << std::endl;
	}
}

// Get the character at position xy on the map 
char Map::getXY(int x, int y) {
	return map[y * mapWidth + x];
}

// Set the character at position xy on the map 
bool Map::setXY(int x, int y, char value) {
	map[y * mapWidth + x] = value; //update value
	return true;
}

Map::~Map()
{
	delete[] map;
}

