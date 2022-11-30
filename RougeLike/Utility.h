#pragma once

namespace utility
{
	//Show or hide the console cursor
	void showConsoleCursor(bool showFlag);

	//Move the console cursor to a given position on the console
	void goToScreenPosition(short C, short R);
}