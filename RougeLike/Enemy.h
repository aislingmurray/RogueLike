#pragma once

#include <random>
#include <ctime>

class Enemy
{
private:
	std::string e_name;

	int e_health;
	int e_attack;
	int e_xp;
	int e_defence;
	int e_level;

	int e_xPos;
	int e_yPos;

public:
	Enemy(std::string name, int health, int attack, int xp, int defence, int level);
	~Enemy();

	void getPosition(int& xPos, int& yPos);
	void setPosition(int xPos, int yPos);
	
	int attackChance();
	int takeDamage(int attackChance);

	std::string getName();
	int getHealth();
	char getMove(int playerX, int playerY);
	char getChar();
};
