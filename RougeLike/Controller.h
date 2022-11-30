#pragma once
#include <string>
#include <conio.h>
#include <vector>
#include "Player.h"
#include "Level.h"

using std::string;
using std::vector;

enum class GameStates
{
	MAIN_MENU, RESUME, SAVE, LOAD, HELP, EXIT
};

class Controller
{

private:
	Player _player;
	Level _level;
	vector<string> _mainMenu = { "***Main Menu***", "New Game", "Load Game", "Instructions", "Help", "Exit" };

public:
	Controller(string levelFileName);
	~Controller();
	void runGame();
	void playerInput();
	void mainMenu();
};