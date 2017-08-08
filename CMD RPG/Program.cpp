#include <iostream>

#include "Game.h"

Game* rpg;

int main()
{
	rpg = new Game();

	std::cout << "Welcome to the first version of my CMD RPG!" << std::endl;

	Log::writeLine("Teste {0}", std::to_string(12));
	Log::breakLine();
	Log::writeLine("Teste {0}");

	std::cin.get();
	std::cin.get();

	return 0;
}