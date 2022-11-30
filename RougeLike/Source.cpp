#include <iostream>
#include <string>
#include <conio.h>

#include "Controller.h"

using std::cout;
using std::cin;
using std::string;

int main()
{
	Controller controller("C:\\Users\\danny\\Git Repos\\RogueLike\\RougeLike\\Levels\\Level_1.level");

	controller.runGame();

	cout << "\nPress ENTER to continue...\n";
	_getch();
	return 0;
}