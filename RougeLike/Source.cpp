#include <iostream>
#include <string>
#include <conio.h>

#include "GameController.h"

int main()
{
	GameController gameController("C:\\Users\\danny\\Git Repos\\RogueLike\\RougeLike\\Levels\\Level_1.level");

	gameController.runGame();

	std::cout << "\nPress ENTER to continue...\n";
	_getch();
	return 0;
}