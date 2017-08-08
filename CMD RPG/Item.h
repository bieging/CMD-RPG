#ifndef ITEM_H
#define ITEM_H

#pragma once

#include <vector>

#include "Log.h"

class Item
{
public:
	std::string name;
	std::vector<std::string> descriptions;
	
	double weight;
	
	Item();
	~Item();
private:
	const int maxDescriptions = 10;
};

#endif // !ITEM_H