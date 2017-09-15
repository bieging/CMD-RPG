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
#include "Player.h"

enum class GameState
{
	SPLASH,
	START,
	CREATE_CHARACTER,
	OPEN_CHARACTER,
	LOADED_PLAYER,
	GAME_MAIN,
	GAME_BATTLE,
	GAME_INVENTORY,
	GAME_EQUIPMENT,
	RUNNING,
	EXIT,
	RESET_STATE
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

	void addPlayer(std::shared_ptr<Player> player);
private:
	void init();
	void printAvailablePlayers();
	bool getPlayer(int id);

	GameState m_LastState;

	std::vector<std::shared_ptr<Player>> availablePlayers;
	std::shared_ptr<Player> currentPlayer;
};

#endif // !GAME_H