#include <iostream>

#include "Game.h"

Game* rpg;

int main()
{
	std::cout << "Welcome to the first version of my CMD RPG!" << std::endl;

	rpg = new Game(GameState::START);

	while (rpg->m_State != GameState::EXIT)
	{
		rpg->update();

		rpg->processInput();

		rpg->draw();
	}

	std::cin.get();
	std::cin.get();

	return 0;
}