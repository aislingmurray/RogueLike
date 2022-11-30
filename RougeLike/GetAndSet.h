#pragma once
class GetAndSet {
public:
	GetAndSet();

	//SETTERS
	virtual void setPosition(int x, int y);  // used for setting player and enemy position

	//GETTERS
	virtual void getPosition(int& x, int& y) = 0;	 // used for getting player and enemy position

	//private:

	int _x;
	int _y;
};