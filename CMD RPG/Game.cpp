#include "Game.h"

std::ifstream ifs;
std::ofstream ofs;

Game::Game(GameState state)
{
	m_State = state;

	init();
}

Game::~Game()
{
}

void Game::update()
{

}

void Game::processInput()
{

}

void Game::draw()
{
	m_State = GameState::EXIT;
}

void Game::init()
{
	ifs.open("Resources/monsters.rpg");

	loadMonsters();
}

///
///	@brief: Loads all monster types from file
///
void Game::loadMonsters()
{
	if (ifs.is_open())
	{
		std::string line, name, value;
		int pos;

		while (std::getline(ifs, line))
		{
			if (line.size() > 0)
			{
				if (line.at(0) == '[')
				{
					Entity entity;

					entity.m_Name = line.substr(1, line.size() - 1);

					// Loads LifePoints
					std::getline(ifs, line);
					pos = line.find_first_of('=');
					name = line.substr(0, pos);
					if (name == std::string("LifePoints"))
					{
						value = line.substr(pos + 1, line.size());
						entity.m_LifePoints = stoi(value);
					}
					else
					{
						Log::writeLine(std::string("Monster {0} incorrectly defined"), entity.m_Name);
						break;
					}

					// Loads AttackPower
					std::getline(ifs, line);
					pos = line.find_first_of('=');
					name = line.substr(0, pos);
					if (name == std::string("AttackPower"))
					{
						value = line.substr(pos + 1, line.size());
						entity.m_AttackPower = stoi(value);
					}
					else
					{
						Log::writeLine(std::string("Monster {0} incorrectly defined"), entity.m_Name);
						break;
					}

					// Loads Accuracy
					std::getline(ifs, line);
					pos = line.find_first_of('=');
					name = line.substr(0, pos);
					if (name == std::string("Accuracy"))
					{
						value = line.substr(pos + 1, line.size());
						entity.m_Accuracy = stoi(value);
					}
					else
					{
						Log::writeLine(std::string("Monster {0} incorrectly defined"), entity.m_Name);
						break;
					}

					// Loads Defence
					std::getline(ifs, line);
					pos = line.find_first_of('=');
					name = line.substr(0, pos);
					if (name == std::string("Defence"))
					{
						value = line.substr(pos + 1, line.size());
						entity.m_Defence = stoi(value);
					}
					else
					{
						Log::writeLine(std::string("Monster {0} incorrectly defined"), entity.m_Name);
						break;
					}

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

///
///	@brief: Loads all weapons from file
///
void Game::loadWeapons()
{

}