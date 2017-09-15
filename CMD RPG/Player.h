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
	int m_Id;
	
	void setValues(int id, int level, std::string name);
	void print();

	Player();
	~Player();

private:
	int m_Level;

	std::string m_Name;

	Inventory m_mainInventory;
	std::vector<Inventory> m_extraInventories;

	void addItem(Item item);
	void removeItem(Item item);
};

#endif // !PLAYER_H