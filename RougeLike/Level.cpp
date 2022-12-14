#include "Level.h"
#include "Utility.h"

Level::Level(){}

void Level::load(Player& player) 
{     
	levelFile = "Level1.txt";
	std::ifstream file;
	file.open(levelFile);
	if (file.fail()) 
	{
		std::cout << "Error";
		system("PAUSE");
		exit(0);
	}

	std::string line;

	utility::gotoScreenPosition(0, 0);

	while (getline(file, line)) 
	{
		m_levelData.push_back(line);
	}
	file.close();

	char tile;

	for (unsigned int i = 0; i < m_levelData.size(); i++) 
	{
		for (unsigned int j = 0; j < m_levelData[i].size(); j++) 
		{
			tile = m_levelData[i][j];

			switch (tile) {
			case'@'://Player
				player.setPosition(j, i);
				player.init(15, 4, 0);
				break;
			case'#'://Walls
				m_levelData[i][j] = (char)(219);
				break;
			default:
				break;
			}
		}
	}
}


void Level::print(Player &player) 
{
	//Clear screen
	system("CLS");
	//Clears the stream
	std::cout << std::flush;

	for (unsigned int i = 0; i < m_levelData.size(); i++)
	{
		std::cout << m_levelData[i] << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Move player with w/a/s/d" << std::endl;

	std::cout << "Health :" << player.m_health << "   Attack :" << player.m_attack << "    Gold:" << player.m_gold << std::endl;
	std::cout << "\n ";

}

void Level::movePlayer(char input, Player& player)
{
	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);

	switch (input)
	{
	case'w':
	case'W':
		//Inverted Y axis for some reason
		playerMoveProcess(player, playerX, playerY - 1);
		break;
	case's':
	case'S':
		playerMoveProcess(player, playerX, playerY + 1);
		break;
	case'a':
	case'A':
		playerMoveProcess(player, playerX - 1, playerY);
		break;
	case'd':
	case'D':
		playerMoveProcess(player, playerX + 1, playerY);
		break;
	default:
		std::cout << "\nInvalid Input" << std::endl;
		system("PAUSE");
		break;
	}
}

void Level::playerMoveProcess(Player& player, int targetX, int targetY)
{
	int playerX;
	int playerY;

	player.getPosition(playerX, playerY);
	char moveTile = getTile(targetX, targetY);

	switch (moveTile)
	{
	case' ':
		//Swaps the player char with the one in the space its moving too
		player.setPosition(targetX, targetY);
		setTile(playerX, playerY, ' ');
		setTile(targetX, targetY, '@');
		break;
	case'+':
		player.setPosition(targetX, targetY);
		setTile(playerX, playerY, '+');
		setTile(targetX, targetY, '@');
		break;
	case'#':
		player.setPosition(targetX, targetY);
		setTile(playerX, playerY, '#');
		setTile(targetX, targetY, '@');
		break;
	case((char)(219)):
		system("PAUSE");
		break;
		//Gold and enemy collision goes in here
	case'*':
		m_gold.increaseScore(player, 5);
		setTile(targetX, targetY, ' ');
		break;
	case'!':
		win(player);
		break;
	default:
		break;
	}
}

//Program crashes here (vector subscript is out of range)
char Level::getTile(int x, int y) 
{
	char a = m_levelData[y][x];
	return m_levelData[y][x];
}

void Level::setTile(int x, int y, char tile) 
{
	m_levelData[y][x] = tile;
}

void Level::win(Player& player)
{
	if (player.m_gold >= 20)
	{
		std::cout << "YOU WIN!" << std::endl;
		system("PAUSE");
		exit(0);
	}
	else
	{
		std::cout << "You do not have enough Gold!" << std::endl;
		system("PAUSE");
		return;
	}
}


Level::~Level() {}