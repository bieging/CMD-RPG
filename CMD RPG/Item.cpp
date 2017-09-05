#include "Item.h"



Item::Item(std::string newName, std::string newDescription, double newWeight)
{
	m_Name = newName;
	m_MainDescription = newDescription;
	weight = newWeight;
}

Item::Item(const Item& item)
{
	m_Name = item.m_Name;
	m_MainDescription = item.m_MainDescription;
}

Item::~Item()
{
}
