#include "Gold.h"

Gold::Gold() {}

Gold::~Gold() {}

void Gold::increaseScore(Player& player, int value)
{
	player.m_gold += value;
}