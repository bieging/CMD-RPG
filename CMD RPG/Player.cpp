#include "Player.h"

Player::Player()
{
	m_Id = -1;
	m_Level = 1;
}

Player::~Player()
{
}

void Player::setValues(int id, int level, std::string name)
{
	m_Id = id;
	m_Level = level;
	m_Name = name;
}

void Player::print()
{
	std::string playerData = "Player " + std::to_string(m_Id) + " - " + m_Name;
	Log::writeLine(playerData);
}