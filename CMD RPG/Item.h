#ifndef ITEM_H
#define ITEM_H

#pragma once

#include <vector>
#include <typeinfo>

#include "Log.h"

class Item
{
public:
	double weight;
	std::string m_Name;
	std::string m_MainDescription;
	std::vector<std::string> m_ExtraDescriptions;
	
	Item() {}
	Item(std::string, std::string, double);
	Item(const Item& item);
	void operator=(const Item& item)
	{
		m_Name = item.m_Name;
		m_MainDescription = item.m_MainDescription;
		m_ExtraDescriptions = item.m_ExtraDescriptions;
	}
	~Item();
protected:

//public:
//	std::string getName();
//	std::string getMainDescription();
//	std::vector<std::string> getExtraDescriptions();
private:
	const int maxDescriptions = 10;
};

#endif // !ITEM_H