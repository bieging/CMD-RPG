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
	START,
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
};

#endif // !GAME_H