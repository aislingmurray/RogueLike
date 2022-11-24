#pragma once

#include <string>

class Enemy
{
private:
	std::string m_name;
	int m_maxHealth;
	int m_currentHealth;
	int m_xp;
	int m_attackDamage;

public:
	Enemy(std::string name, int maxHealth, int xp, int attackDamage);
	~Enemy();

	//Getters and Setters
	int getHealth();
	int getXp();
	int getAttackDamage();

	void attack();
};