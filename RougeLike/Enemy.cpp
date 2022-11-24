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

void Enemy::getPosition(int& x, int& y)//AaronAdded
{
	x = _x;
	y = _y;
}

void Enemy::setPosition(int x, int y)//AaronAdded
{
	_x = x;
	_y = y;
}

int Enemy::attackChance()//AaronAdded
{
	static mt19937 randomEngine(time(NULL));
	uniform_int_distribution<int> attackPower(0, _attack);

	return attackPower(randomEngine);
}

int Enemy::takeDamage(int attackChance)//AaronAdded
{
	attackChance -= _defence;

	//check if attack does damage
	if (attackChance > 0)
	{
		_health -= attackChance;

		//Check if it died
		if (_health <= 0)
			return _xp;
	}

	return 0;
}

string Enemy::getEnemyName()//Aaron Added
{
	return _name;
}

char Enemy::getChar()//Aaron Added
{
	return _unitTile;
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

char Enemy::getMove(int playerX, int playerY) // AaronAdded
{
	static mt19937 randomEngine(time(NULL));
	uniform_int_distribution<int> moveRoll(0, 6);

	int distance; //from Player
	int dx = _x - playerX;
	int dy = _y - playerY;
	int adx = abs(dx);
	int ady = abs(dy);
	int randomMove;
	distance = adx + ady;

	if (distance <= 5)
	{
		if (adx > ady) //Moves along x-axis
		{
			if (dx > 0) //Right of player
				return 'a';

			else
				return 'd';
		}

		else
		{
			if (dy > 0) //Right of player
				return 'w';

			else
				return 's';
		}
	}

	randomMove = moveRoll(randomEngine);

	switch (randomMove)
	{
	case 0:
		return 'w';

	case 1:
		return 'a';

	case 2:
		return 's';

	case 3:
		return 'd';

	default:
		return '.';
	}
}