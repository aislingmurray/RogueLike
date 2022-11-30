#pragma once
#include <string>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "GetAndSet.h"
#define randomGen(a,b) (rand() %a + b)

class Enemy : public GetAndSet
{
public:
	Enemy(std::string name, char tile, int health, int attack);  //initiate enemy

	char getTile() { return m_tile; }                    // get the enemy tile representation

	void getPosition(int& x, int& y) {                   // get enemy position on map
		x = m_x;
		y = m_y;
	}

	char getMove(int playerX, int playerY);              // Move the enemy using AI

	std::string m_name;
	int m_health;
	int m_attack;
	char m_tile;


};


