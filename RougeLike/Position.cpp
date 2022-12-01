#include "Position.h"

Position::Position() 
{
	//Only initialised variables
	m_x = 0;
	m_y = 0;
}

void Position::setPosition(int x, int y)
{
	m_x = x;
	m_y = y;
}