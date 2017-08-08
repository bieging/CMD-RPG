#include "Inventory.h"

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}

void Inventory::addItem(Item item)
{
	if (m_items.size() < m_size)
	{
		m_items.push_back(item);
	}
	else
	{
		Log::writeLine("Inventory is full");
	}
}

void Inventory::removeItem(int itemID)
{
	if (itemID < m_size && itemID >= 0)
	{
		m_items.erase(m_items.begin() + itemID);
	}
}

void Inventory::clear()
{
	m_items.clear();
}

void Inventory::display()
{
	Log::writeLine("Items in inventory: {0}", std::to_string(m_id));

	for (size_t i = 0; i < m_items.size(); i++)
	{
		Log::writeLine("Item {0}", std::to_string(i));
		Log::writeLine("Name: {0}", m_items.at(i).name);
		
		Log::writeLine("Description(s)");
		
		for (size_t j = 0; j < m_items.at(j).descriptions.size(); j++)
		{
			Log::writeLine("Name: {0}", m_items.at(j).descriptions.at(j));
		}

		Log::writeLine("Weight: {0}", std::to_string(m_items.at(i).weight));
		Log::breakLine();
	}
}
