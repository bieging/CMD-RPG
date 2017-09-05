#ifndef GAME_H
#define GAME_H

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Log.h"
#include "Entity.h"

class Game
{
public:
	std::vector<Entity> entities;

	Game();
	~Game();

	void update();
private:
	void init();

	void loadMonsters();
};

#endif // !GAME_H