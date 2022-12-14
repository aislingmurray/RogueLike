#include "Enemy.h"



Enemy::Enemy(std::string name, char tile, int health, int attack) {   //Initiate Enemy 
	m_name = name;
	m_health = health;
	m_attack = attack;
	m_tile = tile;
}

char Enemy::getMoveEnemy(int playerX, int playerY) {      // Calaculates the movement of the Enemy

	int distanceFromPlayer;
	int dx = m_x - playerX;
	int dy = m_y - playerY;
	int adx = abs(dx);
	int ady = abs(dy);
	distanceFromPlayer = adx + ady;           // calculate the distance from the player to decide the next move
	if (distanceFromPlayer <= 50) {
		if (adx > ady) {
			if (dx > 0) {
				return 'a';
			}
			else {
				return 'd';
			}
		}
		else {
			if (dy > 0) {
				return 'w';
			}
			else {
				return 's';
			}
		}
	}

	int randomMove = randomGen(5, 1);           // randomly moves to one of direction when player is not class
	switch (randomMove) {
	case 1:
		return 'a';
	case 2:
		return 'w';
	case 3:
		return 's';
	case 4:
		return 'd';
	default:
		return '.';

	}
}

void Enemy::getPosition(int& x, int& y)
{
	m_x = x;
	m_y = y;
}

char Enemy::getTile()
{
	return m_tile;
}



