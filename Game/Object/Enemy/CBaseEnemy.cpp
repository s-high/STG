#include "CBaseEnemy.h"



CBaseEnemy::CBaseEnemy(double x, double y,int hp) : CBaseObject(x,y)
{
	this->pHP = std::make_shared<CNormalHP>(hp);
}


CBaseEnemy::~CBaseEnemy()
{
}
