#pragma once

#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Player.h"
#include "FileHandler.h"

class Level
{
private:
	const int x = 50;
	const int y = 0;
	double z = 0;

	FileHandler m_fileHandler;
	std::string levelFile;
	std::vector <std::string>  m_levelData;

	Player _player;

	//Processes the player movements on the level
	void playerMoveProcess(Player& player, int targetX, int targetY);

public:
	Level();
	~Level();

	//Loads the level
	void load(Player& player);
	//Player movement
	void movePlayer(char input, Player& player);
	//Prints the level
	void print(Player& player);
	
	//Getter and Setter for tile
	char getTile(int x, int y);
	void setTile(int x, int y, char tile);
};
