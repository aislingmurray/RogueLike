#include <string>
#include <iostream>
#include "Enemy.h"

Enemy::Enemy(std::string name, int maxHealth, int xp, int attackDamage)
{
	m_name = name;
	m_maxHealth = maxHealth;
	m_currentHealth = m_maxHealth;
	m_xp = xp;
	m_attackDamage = attackDamage;
}

Enemy::~Enemy()
{
	std::cout << m_name << " Destructor" << std::endl;
}

int Enemy::getHealth()
{
	return m_currentHealth;
}

int Enemy::getXp()
{
	return m_xp;
}

int Enemy::getAttackDamage()
{
	return m_attackDamage;
}

void Enemy::attack()
{
	std::cout << m_name << " attacks player" << std::endl;
}