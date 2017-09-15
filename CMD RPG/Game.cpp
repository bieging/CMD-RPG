#include "Game.h"

std::ifstream ifs;
std::ofstream ofs;

Game::Game(GameState state)
{
	m_State = state;
	m_LastState = m_State;

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
	switch (m_State)
	{
		case GameState::START:
			if (m_LastState != m_State)
			{
				system("CLS");
				m_LastState = m_State;
				std::string input;

				Log::writeLine("Press 1 to open an existing character");
				Log::writeLine("Press 2 to create a new character");
				Log::writeLine("Press 3 to exit the game");

				input = std::cin.get();

				if (input == std::string("1"))
				{
					m_State = GameState::OPEN_CHARACTER;
				}
				else if (input == std::string("2"))
				{
					m_State = GameState::CREATE_CHARACTER;
				}
				else if (input == std::string("3"))
				{
					m_State = GameState::EXIT;
				}
				else
				{
					Log::writeLine("Invalid input");
					std::cin.get();
					m_State = GameState::RESET_STATE;
				}
			}
			break;

		case GameState::OPEN_CHARACTER:
			if (m_LastState != m_State)
			{
				system("CLS");
				m_LastState = m_State;
				int playerId;
				std::string playerIdStr;

				Log::writeLine("Select an existing character");

				printAvailablePlayers();
				
				std::cin.get();
				std::cin >> playerIdStr;
				playerId = std::stoi(playerIdStr);

				if (getPlayer(playerId))
				{
					m_State = GameState::LOADED_PLAYER;
				}
				else
				{
					Log::writeLine("Invalid player");

					std::cin.get();
					std::cin.get();

					m_State = GameState::RESET_STATE;
				}
			}
			break;

		case GameState::LOADED_PLAYER:
		if (m_LastState != m_State)
		{
			system("CLS");
			m_LastState = m_State;

			std::string cmd;

			Log::writeLine("Loaded Player Successfully");
			Log::writeLine("Press 'P' to play and 'E' to return to start menu");

			std::cin.get();
			cmd = std::cin.get();

			if (cmd == "P")
			{
				m_State = GameState::GAME_MAIN;
			}
			else if (cmd == "E")
			{
				m_State = GameState::START;
			}
			else
			{
				Log::writeLine("Invalid input");

				std::cin.get();
				std::cin.get();

				m_State = GameState::RESET_STATE;
			}
			break;
		}

		case GameState::CREATE_CHARACTER:
			if (m_LastState != m_State)
			{
				system("CLS");
				m_LastState = m_State;

				Log::writeLine("Create a new character");

				std::cin.get();
				std::cin.get();

				m_State = GameState::START;
			}
			break;

		case GameState::RESET_STATE:
			m_State = m_LastState;
			m_LastState = GameState::RESET_STATE;
			system("CLS");
			break;

		default:
			break;
	}
}

void loadMonsters(Game* game);
void loadWeapons(Game* game);
void loadPlayers(Game* game);

void Game::init()
{
	ifs.open("Resources/monsters.rpg");

	loadMonsters(this);

	ifs.open("Resources/weapons.rpg");

	loadWeapons(this);

	ifs.open("Resources/players.rpg");

	loadPlayers(this);
}

void Game::printAvailablePlayers()
{
	for (auto& player : availablePlayers)
	{
		player->print();
	}
}

bool Game::getPlayer(int id)
{
	for (auto& player : availablePlayers)
	{
		if (player->m_Id == id)
		{
			currentPlayer = player;
			return true;
		}
	}

	return false;
}

void Game::addPlayer(std::shared_ptr<Player> player)
{
	availablePlayers.push_back(player);
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

					game->items.addWeapon(std::move(weapon));
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

static void loadPlayers(Game* game)
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
					std::shared_ptr<Player> player = std::make_shared<Player>();

					std::string p_Name;
					int p_Id, p_Level;

					p_Name = line.substr(1, line.size() - 2);

					// Loads Id
					std::getline(ifs, line);
					pos = line.find_first_of('=');
					name = line.substr(0, pos);
					if (name == std::string("Id"))
					{
						value = line.substr(pos + 1, line.size());
						p_Id = std::stoi(value);
					}
					else
					{
						Log::writeLine(std::string("Player {0} incorrectly defined"), std::to_string(p_Id));
						break;
					}

					// Loads Level
					std::getline(ifs, line);
					pos = line.find_first_of('=');
					name = line.substr(0, pos);
					if (name == std::string("Level"))
					{
						value = line.substr(pos + 1, line.size());
						p_Level = std::stoi(value);
					}
					else
					{
						Log::writeLine(std::string("Player {0} incorrectly defined"), std::to_string(p_Id));
						break;
					}

					player->setValues(p_Id, p_Level, p_Name);
					game->addPlayer(std::move(player));
				}
			}
		}

		ifs.close();
	}
	else
	{
		Log::writeLine(std::string("Unable to load players file"));
	}
}