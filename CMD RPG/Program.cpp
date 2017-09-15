#include <iostream>
#include <stdlib.h>

#include "Game.h"

Game* rpg;

int main()
{
	std::cout << "Welcome to the first version of my CMD RPG!" << std::endl;

	rpg = new Game(GameState::SPLASH);

	std::cout << "Press enter to continue!" << std::endl;
	std::cin.get();

	rpg->m_State = GameState::START;

	while (rpg->m_State != GameState::EXIT)
	{
		rpg->update();

		rpg->processInput();

		rpg->draw();
	}

	delete rpg;

	return 0;
}