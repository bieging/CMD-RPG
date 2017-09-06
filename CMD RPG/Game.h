#ifndef GAME_H
#define GAME_H

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Log.h"
#include "Entity.h"

enum class GameState
{
	START,
	RUNNING,
	EXIT
};

class Game
{
public:
	GameState m_State;

	std::vector<Entity> entities;

	Game(GameState state);
	~Game();

	void update();
	void processInput();
	void draw();
private:
	void init();

	void loadMonsters();
	void loadWeapons();
};

#endif // !GAME_H