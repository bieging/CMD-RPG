#ifndef ITEM_CONTAINER_H
#define ITEM_CONTAINER_H

#pragma once

#include <vector>
#include <memory>

#include "Item.h"
#include "Weapon.h"

class ItemContainer
{
public:
	std::vector<std::unique_ptr<Weapon>> weapons;

	ItemContainer();
	~ItemContainer();
};

#endif // !ITEM_CONTAINER_H