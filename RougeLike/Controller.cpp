#include <Windows.h>

#include "Controller.h"

#define WINDOWSIZE_X 1500 // in px
#define WINDOWSIZE_Y 600 // in px


Controller::Controller(string levelFileName)
{
	_player.init(100, 10, 10, 0, 1);
	_level.loadLevel(levelFileName, _player);
	//_level.displayLevel();
}

Controller::~Controller()
{
}

void Controller::runGame()
{
	int input = 3;
	bool gameOver = false;

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.left, r.top, WINDOWSIZE_X, WINDOWSIZE_Y, TRUE);

	/*while ((input == 3) || (input == 4))
	{
		switch (input)
		{
			case 1:
				break;

			case 2:
				break;

			case 3: system("cls");

				break;

			case 4: system("cls");
				break;

			default:
				break;
		}
	}*/

	while (!gameOver)
	{
		_level.displayLevel();
		playerInput();
		_level.updateEnemyPosition(_player);
	}
}

void Controller::playerInput()
{
	char input;
	printf("\nConsole.. (w/a/s/d)>> ");
	input = _getch();
	_level.movePlayer(input, _player);
}

void Controller::mainMenu()
{
	for (int i = 0; i < _mainMenu.size(); i++)
	{
		printf("%s\n", _mainMenu[i].c_str());
	}

	system("PAUSE>null");
}