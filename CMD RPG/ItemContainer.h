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
	bool hasLimit;

	int itemLimit;
	int itemCount;

	ItemContainer();
	~ItemContainer();

	bool addWeapon(std::unique_ptr<Weapon> weapon);
	bool removeWeapon(int weaponId);
private:
	std::vector<std::unique_ptr<Weapon>> weapons;
};

#endif // !ITEM_CONTAINER_H