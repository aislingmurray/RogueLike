#include "Enemy.h"

Enemy::Enemy(std::string name, int health, int attack, int defence, int xp, int level)
{
	e_name = name;
	e_health = health;
	e_attack = attack;
	e_defence = defence;
	e_xp = xp;
	e_level = level;
}

Enemy::~Enemy() {}

//Getter and Setter for enemy position
void Enemy::getPosition(int& x, int& y)
{
	x = e_xPos;
	y = e_yPos;
}

void Enemy::setPosition(int x, int y)
{
	e_xPos = x;
	e_yPos = y;
}

// Uses a random generator to determine if the attack does damage or not
int Enemy::attackChance()
{
	static std::mt19937 randomEngine(time(NULL));
	std::uniform_int_distribution<int> attackPower(0, e_attack);

	return attackPower(randomEngine);
}

//Takes damage from player if attackChance holds a value
int Enemy::takeDamage(int attackChance)
{
	attackChance -= e_defence;

	//check if attack does damage
	if (attackChance > 0)
	{
		e_health -= attackChance;

		//Check if it died
		if (e_health <= 0)
			return e_xp;
	}

	return 0;
}

std::string Enemy::getName()
{
	return e_name;
}

int Enemy::getHealth()
{
	return e_health;
}

//Uses a random generator to move the enemy randomly in relation to the player
char Enemy::getMove(int playerX, int playerY)
{
	static std::mt19937 randomEngine(time(NULL));
	std::uniform_int_distribution<int> moveRoll(0, 6);

	int distance; //from Player
	int dx = e_xPos - playerX;
	int dy = e_yPos - playerY;
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