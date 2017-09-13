#ifndef GAME_H
#define GAME_H

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <typeinfo>

#include "Log.h"
#include "ItemContainer.h"
#include "Entity.h"
#include "Item.h"
#include "Weapon.h"

enum class GameState
{
	SPLASH,
	START,
	CREATE_CHARACTER,
	OPEN_CHARACTER,
	GAME_MAIN,
	GAME_BATTLE,
	GAME_INVENTORY,
	GAME_EQUIPMENT,
	RUNNING,
	EXIT
};

class Game
{
public:
	GameState m_State;

	std::vector<Entity> entities;

	ItemContainer items;

	Game(GameState state);
	~Game();

	void update();
	void processInput();
	void draw();
private:
	void init();

	GameState m_LastState;
};

#endif // !GAME_H