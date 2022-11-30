#include "GameController.h"


GameController::GameController(std::string levelFileName)
{
	m_player.init(100, 10, 10, 0, 1);
	m_level.loadLevel(levelFileName, m_player);
	//_level.displayLevel();
}

GameController::~GameController()
{
}

void GameController::runGame()
{
	int input = 3;
	bool gameOver = false;

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
		m_level.displayLevel();
		playerInput();
		m_level.updateEnemyPosition(m_player);
	}
}

void GameController::playerInput()
{
	char input;
	printf("\nConsole.. (w/a/s/d)>> ");
	input = _getch();
	m_level.movePlayer(input, m_player);
}

void GameController::mainMenu()
{
	for (int i = 0; i < m_mainMenu.size(); i++)
	{
		printf("%s\n", m_mainMenu[i].c_str());
	}

	system("PAUSE>null");
}