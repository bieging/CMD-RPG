#include "Entity.h"



Entity::Entity() {}

Entity::Entity(std::string name,
			   int lifepoints,
			   int attackPower,
			   int accuracy,
	           int defence)
	: m_Name(name),
	  m_LifePoints(lifepoints),
	  m_AttackPower(attackPower),
	  m_Accuracy(accuracy),
	  m_Defence(defence)
{

}


Entity::~Entity()
{
}
