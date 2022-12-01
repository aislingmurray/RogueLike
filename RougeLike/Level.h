#pragma once

#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Player.h"
#include "FileHandler.h"
#include "Gold.h"

class Level
{
private:
	FileHandler m_fileHandler;
	std::string levelFile;
	std::vector <std::string>  m_levelData;

	Player m_player;
	Gold m_gold;

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

	void win(Player& player);
};
