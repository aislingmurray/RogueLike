#include <windows.h>
#include <string>
#include <iostream>
#include "Player.h"
#include "Utility.h"


Player::Player(std::string name, int maxHealth)
{
	m_name = name;
	m_maxHealth = maxHealth;
	m_currentHealth = m_maxHealth;
}

Player::~Player()
{
	std::cout << "Player Destructor" << std::endl;
}

int Player::getHealth()
{
	return m_currentHealth;
}

int Player::getXp()
{
	return m_xp;
}

void Player::setXp(int xp)
{
	m_xp = xp;
}

int Player::getAttackDamage()
{
	return m_attackDamage;
}

void Player::setAttackDamage(int attackDamage)
{
	m_attackDamage = attackDamage;
}

void Player::attack()
{
	std::cout << "Player attack" << std::endl;
}

void Player::pickUpItem()
{
	std::cout << "Player picked up an item" << std::endl;
}
