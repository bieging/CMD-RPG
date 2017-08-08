#ifndef PLAYER_H
#define PLAYER_H

#pragma once

#include <vector>

#include "Log.h"
#include "Item.h"
#include "Inventory.h"

class Player
{
public:
	Player();
	~Player();
private:
	Inventory m_mainInventory;
	std::vector<Inventory> m_extraInventories;

	void addItem(Item item);
	void removeItem(Item item);

};

#endif // !PLAYER_H