#include "CBaseHP.h"



CBaseHP::CBaseHP(int hp)
{
	this->hp = hp;
	this->maxHP = hp;
}

void CBaseHP::addDamage(int damage) {
	this->hp -= damage;
}

int CBaseHP::getHP() { return this->hp; }
double CBaseHP::getPercent() { return double(this->hp) / double(this->maxHP); }

CBaseHP::~CBaseHP()
{
}
