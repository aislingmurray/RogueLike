#pragma once

#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Utility.h"
#include "Enemy.h"

//Used as backup if file cant load
//#define WALLCHAR '#'
//#define FLOORCHAR ' '

//Both in px
#define WINDOWSIZE_X 1500
#define WINDOWSIZE_Y 800

class Level
{
private:
	//Level size
	int levelHeight;
	int levelWidth;

	//pointer to level
	char* level;

	std::vector<std::string> m_levelData;
	std::vector<std::string> m_levelPath;

public:
	Level();
	~Level();

	void loadLevel(int width, int height);

	//Get and set the character position
	char getXY(int x, int y);
	bool setXY(int x, int y, char value);

	//Print out the map
	void printLevel(std::string line);

};
