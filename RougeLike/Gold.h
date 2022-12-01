#pragma once

#include <iostream>

class Gold
{
private:
	int g_value;

public:
	Gold(int value);
	~Gold();

	void increaseScore(int value);
};