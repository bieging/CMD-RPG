#ifndef INVENTORY_H
#define INVENTORY_H

#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Log.h"
#include "Item.h"

class Inventory
{
public:
	Inventory();
	~Inventory();

	void addItem(Item item);
	void removeItem(int itemID);
	void display();
private:
	int m_size;
	int m_id;

	std::vector<Item> m_items;

	void clear();
};

#endif // !INVENTORY_H