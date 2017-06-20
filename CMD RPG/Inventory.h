#ifndef INVENTORY_H
#define INVENTORY_H

#pragma once

#include <vector>

#include "Item.h"

class Inventory
{
public:
	Inventory();
	~Inventory();
private:
	std::vector<Item> inventory;
};

#endif // !INVENTORY_H