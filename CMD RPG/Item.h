#ifndef ITEM_H
#define ITEM_H

#pragma once

#include <vector>

#include "Log.h"

class Item
{
public:
	std::string m_Name;
	std::string m_MainDescription;
	std::vector<std::string> m_ExtraDescriptions;
	
	double weight;
	
	Item(std::string, std::string, double);
	Item(const Item& item);
	void operator=(const Item& item)
	{
		m_Name = item.m_Name;
		m_MainDescription = item.m_MainDescription;
		m_ExtraDescriptions = item.m_ExtraDescriptions;
	}
	~Item();
private:
	const int maxDescriptions = 10;
};

#endif // !ITEM_H