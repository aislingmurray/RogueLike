#pragma once

#include <string>

#include "Position.h"

class Player : public Position
{
public:
	//Variables public so they can be accessed in level.cpp to print their values
	int m_health;
	int m_attack;
	int m_gold;

	Player();

	//Init used so player can be created without initialising until its needed
	void init(int health, int attack, int gold);

	void getPosition(int& x, int& y);
};