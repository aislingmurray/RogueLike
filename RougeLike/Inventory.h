#pragma once

#include <vector>

#include "Player.h"

class Inventory
{
private:
	std::vector<std::string> inventory;

public:
	Inventory();
	~Inventory();

	void addItem();
	void printInventory();

};
