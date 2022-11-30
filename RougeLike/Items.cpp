#include "Item.h"



Item::Item() {
}


void Item::useItem(Player& player) { // function overload to use potion
	int potion = 4;
	toPotion = &(player._health);
	*toPotion += potion;
	cout << "You used a potion, healed for 4 health !" << endl;
	system("PAUSE");
}

Item::~Item() {
	delete toPotion;
}