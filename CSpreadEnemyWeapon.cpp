#include "CSpreadEnemyWeapon.h"
#include "CGameManager.h"


CSpreadEnemyWeapon::CSpreadEnemyWeapon(std::shared_ptr<CBaseEnemyBulletFactory> pEBFtr, double speed, double diffusion, int MAX_COOL_TIME) : CBaseEnemyWeapon(pEBFtr)
{
	this->speed = speed;
	this->diffusion = diffusion;
	this->MAX_COOL_TIME = MAX_COOL_TIME;
	this->shotCoolTime = MAX_COOL_TIME;
	this->n = 1;
}

CSpreadEnemyWeapon::CSpreadEnemyWeapon(std::shared_ptr<CBaseEnemyBulletFactory> pEBFtr, double speed, double diffusion, int MAX_COOL_TIME,int n) : CBaseEnemyWeapon(pEBFtr)
{
	this->speed = speed;
	this->diffusion = diffusion;
	this->MAX_COOL_TIME = MAX_COOL_TIME;
	this->shotCoolTime = MAX_COOL_TIME;
	this->n = n;
}


void CSpreadEnemyWeapon::attack(CBaseObject* o) {
	this->shotCoolTime -= 1;
	if (this->shotCoolTime <= 0) {
		for (int i = 0;i < this->n;i++) {
			double angle = atan2(CGameManager::pPlayer->getY() - o->getY(), CGameManager::pPlayer->getX() - o->getX());
			angle += this->diffusion * CRandom::getInstance()->getRandom() * 2 - this->diffusion;

			CGameManager::pEnemyBulletManager->addObject(
				this->pEBFtr->create(o->getX(), o->getY(), std::make_shared<CStraightMove>(cos(angle) * this->speed, sin(angle) * this->speed), 10)
			);
		}
		this->shotCoolTime = this->MAX_COOL_TIME;
	}
}

CSpreadEnemyWeapon::~CSpreadEnemyWeapon()
{
}
