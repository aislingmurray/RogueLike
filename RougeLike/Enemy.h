#pragma once

#include <string>
#include <random>
#include <ctime>

using std::string;
using std::mt19937;
using std::uniform_int_distribution;
using std::time;

class Enemy
{
private:
	string _name;
	char _unitTile;

	int _health;
	int _attack;
	int _xp;
	int _defence;
	int _level;

	int _x;
	int _y;

public:
	Enemy(std::string name, char unitTile, int health, int attack, int defence, int xp, int level);
	~Enemy();

	//Getters and Setters
	void getPosition(int& x, int& y);
	void setPosition(int x, int y);
	int attackChance();
	int getHealth();//Getting Enemy Health
	int getXp();//Getting Enemy XP
	int getAttackDamage(int attackChance);//Get damage done to enemy
	string getEnemyName();
	int getEnemyHealth();
	char getMove(int playerX, int playerY);
	char getChar();

	void attack();
};