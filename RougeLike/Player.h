#pragma once

#include <random>
#include <ctime>
#include <vector>

class Player
{
private:
	std::string m_name;
	int m_health;
	int m_xp;
	int m_attack;
	int m_defence;
	int m_level;
	int m_xpThreshold = 5;

	int m_x;
	int m_y;

public:
	Player();
	~Player();

	void init(int health, int attack, int defence, int xp, int level);


	void getPosition(int& x, int& y);
	void setPosition(int x, int y);

	int attackChance();
	int takeDamage(int attackChance);
	void addXP(int xp);
	int getPlayerHealth();
	void unknownEncounter();
};