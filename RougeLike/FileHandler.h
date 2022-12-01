#pragma once

#include <string>
#include <vector>

class FileHandler
{
private:
	//Stores the string from the text file
	std::vector<std::string> m_openTitle;

public:
	FileHandler();
	~FileHandler();

	void gameTitle(std::string fileName);
};