#pragma once

#include <iostream>

#include "Player.h"

class Gold
{
private:
	int m_value;

public:
	Gold();
	~Gold();

	void increaseScore(Player& player, int value);
};