#ifndef PLAYER_H
#define PLAYER_H

#pragma once

#include <vector>

#include "Inventory.h"

class Player
{
public:
	int lifePoints;
	int level;

	double attackSpeed;
	double attackPower;
	double accuracy;

	Player();
	Player(int);
	~Player();
private:
	int inventoryMaxSize = 10;
	Inventory inventory;
};

#endif // !PLAYER_H