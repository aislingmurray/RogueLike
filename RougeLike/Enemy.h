#pragma once

#include <string>
#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "Position.h"

#define randomGen(a,b) (rand() %a + b)

class Enemy : public Position
{
public:
	std::string m_name;
	int m_health;
	int m_attack;
	char m_tile;

	Enemy(std::string name, char tile, int health, int attack);

	char getTile();

	void getPosition(int& x, int& y);

	char getMoveEnemy(int playerX, int playerY);
};