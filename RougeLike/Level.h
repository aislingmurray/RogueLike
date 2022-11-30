#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <cstdio>
#include <conio.h>

#include "Player.h"
#include "Enemy.h"

class Level
{
private:
	int _levelCount = 1;
	std::vector<string> _levelData;
	std::vector<Enemy> _enemies;
	std::vector<std::string> _levelPath;

	void movePlayer(Player& player, int moveX, int moveY);
	void moveEnemy(Player& player, int enemyIndex, int moveX, int moveY);
	void fightEnemy(Player& player, int targetX, int targetY);
	vector <Enemy> _enemies;

public:
	Level();
	~Level();
	void loadLevel(std::string fileName, Player& player);
	void displayLevel();
	void movePlayer(char move, Player& player);
	void updateEnemyPosition(Player &player);
	char getUnitTile(int x, int y);
	void setUnitTile(int x, int y, char unitTile);
	void saveProgress(int levelNum, int x, int y);
	void clearLevel();

};

