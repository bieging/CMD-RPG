#include "Entity.h"



Entity::Entity() {}

Entity::Entity(std::string name, int lifepoints, int attackPower, int defence)
	: m_Name(name),
	  m_LifePoints(lifepoints),
	  m_AttackPower(attackPower),
	  m_Defence(defence)
{

}


Entity::~Entity()
{
}
