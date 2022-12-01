#pragma once

//Used for both player and enemy position
class Position
{
public:
	int m_x;
	int m_y;

	Position();

	virtual void getPosition(int& x, int& y) = 0;

	//Try without virtual when all working
	virtual void setPosition(int x, int y);
};