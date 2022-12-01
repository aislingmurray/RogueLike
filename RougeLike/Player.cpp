#include "Player.h"

Player::Player(){}

void Player::init(int health, int attack, int gold)
{
	m_health = health;
	m_attack = attack;
	m_gold = gold;
}

void Player::getPosition(int& x, int& y)
{
	m_x = x;
	m_y = y;
}