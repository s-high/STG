#include "CBaseEnemyShot.h"



CBaseEnemyShot::CBaseEnemyShot(std::shared_ptr<CBaseEnemyBulletFactory> pEBFtr)
{
	this->pEBFtr = pEBFtr;
}


CBaseEnemyShot::~CBaseEnemyShot()
{
}
