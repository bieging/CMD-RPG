#include <iostream>

#include "Game.h"

Game* rpg;

int main()
{
	rpg = new Game();

	std::cout << "Welcome to the first version of my CMD RPG!";

	std::cin.get();
	std::cin.get();

	return 0;
}