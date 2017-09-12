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

void loadMonsters(Game* game);
void loadWeapons(Game* game);

void Game::init()
{
	ifs.open("Resources/monsters.rpg");

	loadMonsters(this);

	ifs.open("Resources/weapons.rpg");

	loadWeapons(this);
}

///
///	@brief: Loads all monster types from file
///
void loadMonsters(Game* game)
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

					int teste = 5;

					int *ptr = &teste;

					entity.m_Name = line.substr(1, line.size() - 2);

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

					game->entities.push_back(entity);
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
static void loadWeapons(Game* game)
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
					std::unique_ptr<Weapon> weapon = std::make_unique<Weapon>();

					weapon->m_Name = line.substr(1, line.size() - 2);

					// Loads Description
					std::getline(ifs, line);
					pos = line.find_first_of('=');
					name = line.substr(0, pos);
					if (name == std::string("Description"))
					{
						value = line.substr(pos + 1, line.size());
						weapon->m_MainDescription = value;
					}
					else
					{
						Log::writeLine(std::string("Weapon {0} incorrectly defined"), weapon->m_Name);
						break;
					}

					// Loads AttackPower
					std::getline(ifs, line);
					pos = line.find_first_of('=');
					name = line.substr(0, pos);
					if (name == std::string("AttackPower"))
					{
						value = line.substr(pos + 1, line.size());
						weapon->m_AttackPower = stoi(value);
					}
					else
					{
						Log::writeLine(std::string("Weapon {0} incorrectly defined"), weapon->m_Name);
						break;
					}

					// Loads Accuracy
					std::getline(ifs, line);
					pos = line.find_first_of('=');
					name = line.substr(0, pos);
					if (name == std::string("Accuracy"))
					{
						value = line.substr(pos + 1, line.size());
						weapon->m_Accuracy = stoi(value);
					}
					else
					{
						Log::writeLine(std::string("Weapon {0} incorrectly defined"), weapon->m_Name);
						break;
					}

					game->items.weapons.push_back(std::move(weapon));
				}
			}
		}

		Log::writeLine(std::string("Weapons loaded"));

		ifs.close();
	}
	else
	{
		Log::writeLine(std::string("Unable to load weapons file"));
	}
}