#include <windows.h>
#include <iostream>
#include <string>

#include "Utility.h"
#include "Level.h"
#include "Gold.h"

// map size
#define MAPSIZEX 50
#define MAPSIZEY 35


unsigned int playerPositionX = 1;
unsigned int playerPositionY = 1;
unsigned int newPlayerPositionX = playerPositionX;
unsigned int newPlayerPositionY = playerPositionY;
char playerChar = 2;

/*
unsigned int enemyPositionX = 25;
unsigned int enemyPositionY = 25;
unsigned int newEnemyPositionX = enemyPositionX;
unsigned int newEnemyPositionY = enemyPositionY;
char enemyChar = 77;

unsigned int goldPositionX = 10;
unsigned int goldPositionY = 25;
unsigned int newGoldPositionX = goldPositionX;
unsigned int newGoldPositionY = goldPositionY;
char goldChar = 42;

unsigned int potionPositionX = 35;
unsigned int potionPositionY = 15;
unsigned int newPotionPositionX = potionPositionX;
unsigned int newPotionPositionY = potionPositionY;
char potionChar = 94;
*/

Level level;

void handleInput()
{
	newPlayerPositionX = playerPositionX;
	newPlayerPositionY = playerPositionY;

	if (GetKeyState('W') & 0x8000)
	{
		newPlayerPositionY = playerPositionY - 1;
	}

	if (GetKeyState('S') & 0x8000)
	{
		newPlayerPositionY = playerPositionY + 1;
	}

	if (GetKeyState('D') & 0x8000)
	{
		newPlayerPositionX = playerPositionX + 1;
	}

	if (GetKeyState('A') & 0x8000)
	{
		newPlayerPositionX = playerPositionX - 1;
	}
}

void renderPlayer()
{
	// Draw new player position
	utility::gotoScreenPosition(playerPositionX, playerPositionY);
	std::cout << " ";

	// Draw new player position
	utility::gotoScreenPosition(newPlayerPositionX, newPlayerPositionY);
	std::cout << playerChar;

	// update player position
	playerPositionX = newPlayerPositionX;
	playerPositionY = newPlayerPositionY;

	Sleep(120);
}

/*
void renderEnemy()
{
	// Draw new enemy position
	utility::gotoScreenPosition(enemyPositionX, enemyPositionY);
	std::cout << " ";

	// Draw new enemy position
	utility::gotoScreenPosition(newEnemyPositionX, newEnemyPositionY);
	std::cout << enemyChar;

	// update player position
	enemyPositionX = newEnemyPositionX;
	enemyPositionY = newEnemyPositionY;

	Sleep(120);
}

void renderGold()
{
	// Draw new gold position
	utility::gotoScreenPosition(goldPositionX, goldPositionY);
	std::cout << " ";

	// Draw new gold position
	utility::gotoScreenPosition(newGoldPositionX, newGoldPositionY);
	std::cout << goldChar;

	// update gold position
	goldPositionX = newGoldPositionX;
	goldPositionY = newGoldPositionY;

	Sleep(120);
}

void renderPotion()
{
	// Draw new potion position
	utility::gotoScreenPosition(potionPositionX, potionPositionY);
	std::cout << " ";

	// Draw new potion position
	utility::gotoScreenPosition(newPotionPositionX, newPotionPositionY);
	std::cout << potionChar;

	// update player potion
	potionPositionX = newPotionPositionX;
	potionPositionY = newPotionPositionY;


	Sleep(120);
}
*/

// print messages below map by moving the cursor 
void renderUI() {
	utility::gotoScreenPosition(0, MAPSIZEY);
	std::cout << "Player\t Level 0\t HP: 100";
}

int main()
{
	level.loadLevel(MAPSIZEX, MAPSIZEY);

	while (true)
	{
		Enemy enemy{ "Monster", 50, 30, 50, 20, 3 };
		Gold gold{ 5 };

		// // Handles the input and updates the players position
		handleInput();

		// Render the scene
		renderPlayer();
		/*
		renderEnemy();
		renderGold();
		renderPotion();
		*/

		enemy.getMove(newPlayerPositionX, newPlayerPositionY);

		// Show messages on the screen
		renderUI();
	}

	return 0;

}