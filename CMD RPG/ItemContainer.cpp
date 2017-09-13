#include "ItemContainer.h"

ItemContainer::ItemContainer()
{
	hasLimit = false;
	itemLimit = 0;
	itemCount = 0;
}

ItemContainer::~ItemContainer()
{
}

bool ItemContainer::addWeapon(std::unique_ptr<Weapon> weapon)
{
	if (hasLimit)
	{
		if (itemCount >= itemLimit)
		{
			return false;
		}
	}

	weapons.push_back(std::move(weapon));
	itemCount++;
	return true;
}

bool ItemContainer::removeWeapon(int weaponId)
{
	for (int i = 0; i < weapons.size(); i++)
	{
		if (weapons.at(i)->m_Id == weaponId)
		{
			weapons.erase(weapons.begin() + i);
			return true;
		}
	}

	return false;
}
