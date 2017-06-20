#ifndef WEAPON_H
#define WEAPON_H

#pragma once

#include "Item.h"

class Weapon : Item
{
public:
	double attackPower;
	double accuracy;
	
	Weapon();
	~Weapon();
private:

};

#endif // !WEAPON_H