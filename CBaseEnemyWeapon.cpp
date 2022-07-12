#include "CBaseEnemyWeapon.h"



CBaseEnemyWeapon::CBaseEnemyWeapon(std::shared_ptr<CBaseEnemyBulletFactory> pEBFtr)
{
	this->pEBFtr = pEBFtr;
}

void CBaseEnemyWeapon::attack(CBaseBoss* o) { this->attack(static_cast<CBaseObject*>(o)); }

CBaseEnemyWeapon::~CBaseEnemyWeapon()
{
}
