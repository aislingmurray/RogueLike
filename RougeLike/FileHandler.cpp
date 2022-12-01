#include <fstream>
#include <iostream>
#include <stdlib.h>

#include "FileHandler.h"

FileHandler::FileHandler() {}

//Reads and proccesses the text file containing the level
void FileHandler::gameTitle(std::string fileName)
{
	std::ifstream file;
	file.open("Level1.txt");

	if (file.fail())
	{
		std::cout << "Error opening file" << std::endl;
		//Stops/pauses the program and exits with code 404 
		system("PAUSE");
		exit(404);
	}

	std::string line;

	while (getline(file, line))
	{
		//Adds text lines to vector
		m_openTitle.push_back(line);
	}
	file.close();

	for (unsigned int i = 0; i < m_openTitle.size(); i++)
	{
		std::cout << m_openTitle[i] << std::endl;
	}
	std::cout << std::endl;
}

FileHandler::~FileHandler() {}
