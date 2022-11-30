#include "Level.h"

Level::Level()
{
}

Level::~Level()
{
}

void Level::loadLevel(std::string fileName, Player& player)
{
	std::ifstream levelFile;
	std::string levelLine;

	//Loading Level File
	levelFile.open(fileName);

	if (levelFile.fail())
	{
		perror(fileName.c_str());
		system("PAUSE");
		exit(1);
	}

	while (getline(levelFile, levelLine))
	{
		m_levelData.push_back(levelLine);
	}

	levelFile.close();
	//Level File Loaded

	//Processing Level File
	char unitTile;

	for (int i = 0; i < m_levelData.size(); ++i)
	{
		for (int j = 0; j < m_levelData[i].size(); ++j)
		{
			unitTile = m_levelData[i][j];

			switch (unitTile)
			{
			case '@': player.setPosition(j, i); //Player
				break;

			case 'M': m_enemies.push_back(Enemy("Monster", unitTile, 50, 30, 50, 40, 3));
				m_enemies.back().setPosition(j, i);
				break;

			case 'G': m_enemies.push_back(Enemy("Gargoyle", unitTile, 40, 50, 20, 35, 2));
				m_enemies.back().setPosition(j, i);
				break;

			case 'D': m_enemies.push_back(Enemy("Dragon", unitTile, 100, 100, 100, 100, 10));
				m_enemies.back().setPosition(j, i);
				break;

			case 'S': m_enemies.push_back(Enemy("Skeleton", unitTile, 10, 5, 5, 5, 1));
				m_enemies.back().setPosition(j, i);
				break;
			}
		}
	}
}

void Level::displayLevel()
{
	system("cls");

	for (int i = 0; i < m_levelData.size(); ++i)
	{
		printf("%s", m_levelData[i].c_str());
		printf("\n");
	}
}

void Level::movePlayer(char move, Player& player)
{
	int playerX;
	int playerY;

	player.getPosition(playerX, playerY);

	switch (move)
	{
		//Up
	case 'w':
	case 'W': movePlayer(player, playerX, playerY - 1);
		break;

		//Left
	case 'a':
	case 'A': movePlayer(player, playerX - 1, playerY);
		break;

		//Down
	case 's':
	case 'S': movePlayer(player, playerX, playerY + 1);
		break;

		//Right
	case 'd':
	case 'D': movePlayer(player, playerX + 1, playerY);
		break;

	default: printf("\nInvalid Input!!\n");
		system("PAUSE");
		break;
	}
}

void Level::movePlayer(Player& player, int moveX, int moveY)
{
	int playerX;
	int playerY;
	char input;

	player.getPosition(playerX, playerY);

	char moveToUnit = getUnitTile(moveX, moveY);

	switch (moveToUnit)
	{
	case '.': /*previousUnitUp = _levelData[playerY - 1][playerX];*/
		player.setPosition(moveX, moveY);
		setUnitTile(playerX, playerY, '.');
		setUnitTile(moveX, moveY, '@');
		break;

	case 'D':
	case 'G':
	case 'M':
	case 'S': fightEnemy(player, moveX, moveY);
		break;

	case '#': //printf("\nYou hit a wall!!\n");
		//system("PAUSE>NULL");
		break;

	case '~': player.setPosition(moveX, moveY);
		setUnitTile(playerX, playerY, '~');
		setUnitTile(moveX, moveY, '@');
		break;

	case '?': player.unknownEncounter();
		player.setPosition(moveX, moveY);
		setUnitTile(playerX, playerY, '.');
		setUnitTile(moveX, moveY, '@');
		break;

	case '>': printf("\nConsole...>> Load next level?\nConsole (Y/N): ");
		input = _getch();

		if ((input == 'Y') || (input == 'y'))
		{
			clearLevel();
			m_levelPath.push_back("Levels\\Level_" + std::to_string(++_levelCount) + ".level");
			loadLevel(m_levelPath.back(), player);
		}

	case 'x':
		break;

	default:
		break;
	}
}

char Level::getUnitTile(int x, int y)
{
	return m_levelData[y][x];
}

void Level::setUnitTile(int x, int y, char unitTile)
{
	m_levelData[y][x] = unitTile;
}

void Level::fightEnemy(Player& player, int targetX, int targetY)
{
	int enemyX;
	int enemyY;
	int playerX;
	int playerY;
	int attackPower;
	int attackResult;

	for (int i = 0; i < m_enemies.size(); i++)
	{
		m_enemies[i].getPosition(enemyX, enemyY);

		if ((targetX == enemyX) && (targetY == enemyY))
		{
			//Battle
			attackPower = player.attackChance();
			attackResult = m_enemies[i].takeDamage(attackPower);
			printf("\nPlayer attacked %s with %d damage!!, %s's health: %d", m_enemies[i].getEnemyName().c_str(), attackPower, _enemies[i].getEnemyName().c_str(), _enemies[i].getEnemyHealth());
			system("PAUSE>null");

			if (attackResult > 0)
			{
				player.addXP(attackResult);
				setUnitTile(targetX, targetY, '.');
				displayLevel();
				printf("\n%s died!!!", m_enemies[i].getEnemyName().c_str());
				//remove enemy
				m_enemies[i] = _enemies.back();
				m_enemies.pop_back();
				--i;
				system("PAUSE>null");

				return;
			}

			//Enemy Turn
			attackPower = m_enemies[i].attackChance();
			attackResult = player.takeDamage(attackPower);
			printf("\n%s attacked Player with %d damage!!, Player's health: %d", m_enemies[i].getEnemyName().c_str(), attackPower, player.getPlayerHealth());
			system("PAUSE>null");

			if (attackResult != 0)
			{
				player.getPosition(playerX, playerY);
				setUnitTile(playerX, playerY, 'X');
				displayLevel();
				printf("\nYou died!!!");
				system("PAUSE>null");

				exit(0);
			}

			return;
		}
	}
}

void Level::updateEnemyPosition(Player& player)
{
	char aiMove;
	int playerX;
	int playerY;
	int enemyX;
	int enemyY;

	player.getPosition(playerX, playerY);

	for (int i = 0; i < m_enemies.size(); ++i)
	{
		aiMove = m_enemies[i].getMove(playerX, playerY);
		m_enemies[i].getPosition(enemyX, enemyY);

		switch (aiMove)
		{
			//Up
		case 'w':
			moveEnemy(player, i, enemyX, enemyY - 1);
			break;

			//Left
		case 'a':
			moveEnemy(player, i, enemyX - 1, enemyY);
			break;

			//Down
		case 's':
			moveEnemy(player, i, enemyX, enemyY + 1);
			break;

			//Right
		case 'd':
			moveEnemy(player, i, enemyX + 1, enemyY);
			break;
		}
	}
}

void Level::moveEnemy(Player& player, int enemyIndex, int moveX, int moveY)
{
	int playerX;
	int playerY;
	int enemyX;
	int enemyY;

	m_enemies[enemyIndex].getPosition(enemyX, enemyY);

	char moveToUnit = getUnitTile(moveX, moveY);

	switch (moveToUnit)
	{
	case '.': /*previousUnitUp = _levelData[playerY - 1][playerX];*/
		m_enemies[enemyIndex].setPosition(moveX, moveY);
		setUnitTile(enemyX, enemyY, '.');
		setUnitTile(moveX, moveY, m_enemies[enemyIndex].getChar());
		break;

	case '@': fightEnemy(player, enemyX, enemyY);
		break;

	default:
		break;
	}
}

void Level::clearLevel()
{
	m_levelData.clear();
	m_enemies.clear();
}

void Level::saveProgress(int levelNum, int x, int y)
{
	std::ofstream saveToFile;
}