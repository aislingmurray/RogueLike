#pragma once

#include <vector>

#include "Player.h"

class Inventory : public Player
{
private:
	std::vector<std::string> inventory;

public:
	Inventory();
	~Inventory();

	void addItem();
	void printInventory();

};
