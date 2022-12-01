#pragma once

namespace utility
{
	// Show /hide the console cursor 
	void showConsoleCursor(bool showFlag);

	// Move the console cursor to a given position on the console
	void gotoScreenPosition(short C, short R);
};