#ifndef PLAYER_H
#define PLAYER_H

#pragma once

#include <vector>

#include "Item.h"

class Player
{
public:
	Player();
	~Player();
private:
	int inventoryMaxSize = 10;

	std::vector<Item> inventory;
};

#endif // !PLAYER_H