#pragma once

#include <string>
#include <iostream>
#include <conio.h>

#include "FileHandler.h"
#include "Level.h"
#include "Player.h"

class GameController
{
private:
	const std::string titleFile = "Game.txt";
	FileHandler m_fileHandler;
	Level m_level;
	Player m_player;

public:
	GameController();
	~GameController();

	void gameLoop();
	void mainControl();
};
