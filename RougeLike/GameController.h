#pragma once

#include <string>
#include <conio.h>
#include <vector>

#include "Player.h"
#include "Level.h"

enum class GameStates
{
	MAIN_MENU, RESUME, SAVE, LOAD, HELP, EXIT
};

class GameController
{
private:
	Player m_player;
	Level m_level;
	std::vector<string> m_mainMenu = { "***Main Menu***", "New Game", "Load Game", "Insturctions", "Help", "Exit" };

public:
	GameController(std::string levelFileName);
	~GameController();
	void runGame();
	void playerInput();
	void mainMenu();
};