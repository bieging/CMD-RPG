#include "Item.h"



Item::Item(std::string newName, std::string newDescription, double newWeight)
{
	this->name = newName;
	this->mainDescription = newDescription;
	this->weight = newWeight;
}

Item::~Item()
{
}
