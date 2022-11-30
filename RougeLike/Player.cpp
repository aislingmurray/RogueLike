#include <windows.h>
#include <string>
#include <iostream>
#include "Player.h"


Player::Player()
{

}

Player::~Player()
{
	std::cout << "Player Destructor" << std::endl;
}

void Player::init(int health, int attack, int defence, int xp, int level)
{
	m_health = health;
	m_attack = attack;
	m_defence = defence;
	m_xp = xp;
	m_level = level;
}

void Player::getPosition(int& x, int& y)
{
	x = m_x;
	y = m_y;
}

void Player::setPosition(int x, int y)
{
	m_x = x;
	m_y = y;
}

int Player::attackChance()
{
	static std::mt19937 randomEngine(time(NULL));
	std::uniform_int_distribution<int> attackPower(0, m_attack);

	return attackPower(randomEngine);
}

int Player::takeDamage(int attackChance)
{
	attackChance -= m_defence;

	//if attack does damage after defence
	if (attackChance > 0)
	{
		m_health -= attackChance;

		if (m_health <= 0)
			return 1;
	}

	return 0;
}

void Player::addXP(int xp)
{
	m_xp += xp;

	printf("\nXP gained: %d", xp);
	printf("\nTotal XP: %d", m_xp);
	system("PAUSE>null");

	while (m_xp >= m_xpThreshold) //Level_UP
	{
		m_xpThreshold += m_xpThreshold;
		m_attack += 0.7 * m_attack;
		m_defence += 0.7 * m_defence;
		m_health += 0.7 * m_health;
		++m_level;

		printf("\nLevel UP!!");
		printf("\nLevel Reached: %d", m_level);
		printf("\nPress ENTER to continue...");
		system("PAUSE>null");
	}
}

int Player::getPlayerHealth()
{
	return m_health;
}

void Player::unknownEncounter()
{
	static std::mt19937 randomEngine(time(NULL));
	std::uniform_int_distribution<int> bonusChance(0, 3);

	switch (bonusChance(randomEngine))
	{
	case 0: printf("\nBonus XP: +20 XP");
		addXP(20);
		system("PAUSE>null");
		break;

	case 1: printf("\nAttack: +20");
		m_attack += 20;
		system("PAUSE>null");
		break;

	case 2: printf("\nDefence: +20");
		m_defence += 20;
		system("PAUSE>null");
		break;

	case 3: printf("\nHealth: +20");
		m_health += 20;
		system("PAUSE>null");
		break;
	}
}