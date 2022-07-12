#include "CCircleEnemyWeapon.h"
#include "extern.h"
#include "CCircleEnemyShot.h"

CCircleEnemyWeapon::CCircleEnemyWeapon(std::shared_ptr<CBaseEnemyBulletFactory> pEBFtr, double speed, int MAX_COOL_TIME, int n) : CBaseEnemyWeapon(pEBFtr)
{
	this->pCircleShot = std::make_shared<CCircleEnemyShot>(pEBFtr, speed, n, 0);
	this->MAX_COOL_TIME = MAX_COOL_TIME;
	this->shotCoolTime = MAX_COOL_TIME;

	this->increaseAngle = 0;
}

CCircleEnemyWeapon::CCircleEnemyWeapon(std::shared_ptr<CBaseEnemyBulletFactory> pEBFtr, double speed, int MAX_COOL_TIME, int n, double increaceAngle) : CBaseEnemyWeapon(pEBFtr)
{
	this->pCircleShot = std::make_shared<CCircleEnemyShot>(pEBFtr, speed, n, 0);
	this->MAX_COOL_TIME = MAX_COOL_TIME;
	this->shotCoolTime = MAX_COOL_TIME;

	this->increaseAngle = increaceAngle;
	
}

void CCircleEnemyWeapon::attack(CBaseObject* o) {
	
	shotCoolTime -= 1;
	if (shotCoolTime <= 0) {
		pCircleShot->shot(o);
		pCircleShot->setInitAngle(pCircleShot->getInitAngle() + this->increaseAngle);
		shotCoolTime = MAX_COOL_TIME;
	}
}

CCircleEnemyWeapon::~CCircleEnemyWeapon()
{
}
