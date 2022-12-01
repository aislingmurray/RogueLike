#include "GameController.h"

GameController::GameController()
{
	m_fileHandler.gameTitle(titleFile);

	system("PAUSE");
}

void GameController::gameLoop() {

	m_level.load(m_player);
	bool gameOver = false;

	while (gameOver != true) {                  // main game loop
		m_level.print(m_player);                  // prints the map
		mainControl();                           // user control cycle
	}
}

void GameController::mainControl() {
	char input;
	input = _getch();                                 // User Input
	m_level.movePlayer(input, m_player);                 // Player movement
}

GameController::~GameController() {}