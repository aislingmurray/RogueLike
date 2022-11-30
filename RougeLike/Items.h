#pragma once
#include "Player.h"
#include <iostream>
using namespace std;


class Item {
public:
	Item();
	int* toGold = new int;
	int* toPotion = new int;
	int useItem(int value, Player& player);// function overloading
	void useItem(Player& player);
	friend Item& operator+ (Item& left, Item& right) { left = left + right; return left; }  // operator overloading
	~Item();
};