#pragma once

#include <random>
#include <ctime>
#include <vector>

class Player
{
private:
	std::string m_name;
	int m_maxHealth;
	int m_currentHealth;
	int m_xp;
	int m_attackDamage;
	int m_level;

	int m_x;
	int m_y;

public:
	Player(std::string name, int maxHealth);
	~Player();

	//Getters & Setters
	int getHealth();
	int getXp();
	void setXp(int xp);
	int getAttackDamage();
	void setAttackDamage(int attackDamage);
	void getPosition(int& x, int& y);
	void setPosition(int x, int y);

	//Functions
	void attack();
	void pickUpItem();
};