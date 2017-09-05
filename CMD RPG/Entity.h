#ifndef ENTITY_H
#define ENTITY_H

#pragma once

#include <string>

class Entity
{
public:
	std::string m_Name;
	int m_LifePoints;
	int m_AttackPower;
	int m_Defence;
	
	Entity();
	Entity(std::string name, int lifepoints, int attackPower, int defence);
	~Entity();
private:
};

#endif // !ENTITY_H