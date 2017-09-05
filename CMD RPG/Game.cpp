#include "Game.h"

std::ifstream ifs;
std::ofstream ofs;

Game::Game()
{
	init();
}

Game::~Game()
{
}

void Game::update()
{

}

void Game::init()
{
	ifs.open("Resources/monsters.rpg");

	loadMonsters();
}

void Game::loadMonsters()
{
	if (ifs.is_open())
	{
		std::string line, value;
		int pos;

		while (std::getline(ifs, line))
		{
			if (line.size() > 0)
			{
				if (line.at(0) == '[')
				{
					Entity entity;

					entity.m_Name = line.substr(1, line.size() - 1);

					std::getline(ifs, line);
					pos = line.find_first_of('=');
					value = line.substr(pos + 1, line.size());
					entity.m_LifePoints = stoi(value);

					std::getline(ifs, line);
					pos = line.find_first_of('=');
					value = line.substr(pos + 1, line.size());
					entity.m_AttackPower = stoi(value);

					std::getline(ifs, line);
					pos = line.find_first_of('=');
					value = line.substr(pos + 1, line.size());
					entity.m_Defence = stoi(value);

					entities.push_back(entity);
				}
			}
		}

		Log::writeLine(std::string("Monster loaded"));

		ifs.close();
	}
	else
	{
		Log::writeLine(std::string("Unable to load monsters' file"));
	}
}