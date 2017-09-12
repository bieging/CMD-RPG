#ifndef WEAPON_H
#define WEAPON_H

#pragma once

#include "Item.h"

class Weapon : public Item
{
public:
	double m_AttackPower;
	double m_Accuracy;
	
	Weapon();
	~Weapon();
private:

};

#endif // !WEAPON_H