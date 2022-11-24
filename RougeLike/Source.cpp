#include <iostream>
#include <string>
#include "Player.h"
#include "Enemy.h"
#include "Utility.h"
#include "Map.h"

// map size
#define MAPSIZEX 35
#define MAPSIZEY 25

Map map;

unsigned int playerPositionX = 5;
unsigned int playerPositionY = 5;
unsigned int newPlayerPositionX = playerPositionX;
unsigned int newPlayerPositionY = playerPositionY;
char playerChar = 2;

void handleInput()
{
	newPlayerPositionX = playerPositionX;
	newPlayerPositionY = playerPositionY;

	if (GetKeyState(VK_UP) & 0x8000)
	{
		newPlayerPositionY = playerPositionY - 1;
	}

	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		newPlayerPositionY = playerPositionY + 1;
	}

	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		newPlayerPositionX = playerPositionX + 1;
	}

	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		newPlayerPositionX = playerPositionX - 1;
	}
}

void renderPlayer()
{
	// Draw new player position
	utility::goToScreenPosition(playerPositionX, playerPositionY);
	std::cout << " ";

	// Draw new player position
	utility::goToScreenPosition(newPlayerPositionX, newPlayerPositionY);
	std::cout << playerChar;

	// update player position
	playerPositionX = newPlayerPositionX;
	playerPositionY = newPlayerPositionY;

	Sleep(120);
}

// print messages below map by moving the cursor 
void renderUI() {
	utility::goToScreenPosition(0, MAPSIZEY);
	std::cout << "Player\t Level 0\t HP: 100";
}

int main()
{
	Player player{ "Danny", 100 };
	
	player.attack();


	map.loadMap(MAPSIZEX, MAPSIZEY);

	while (true)
	{
		handleInput();

		renderPlayer();

		renderUI();
	}

	return 0;
}