#ifndef ITEM_H
#define ITEM_H

#pragma once

#include <vector>

class Item
{
public:
	std::string name;
	std::string mainDescription;
	std::vector<std::string> extraDescriptions;
	
	double weight;
	
	Item(std::string, std::string, double);
	~Item();
private:
	const int maxDescriptions = 10;
};

#endif // !ITEM_H