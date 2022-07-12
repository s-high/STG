#include "CRandomEnemyWeapon.h"
#include "CGameManager.h"


CRandomEnemyWeapon::CRandomEnemyWeapon(std::shared_ptr<CBaseEnemyBulletFactory> pEBFtr
	, double speed, int MAX_COOL_TIME, int n = 1) : CBaseEnemyWeapon(pEBFtr)
{
	this->speed = speed;
	this->MAX_COOL_TIME = MAX_COOL_TIME;
	this->shotCoolTime = MAX_COOL_TIME;
	this->n = n;
}

void CRandomEnemyWeapon::attack(CBaseObject* o) {
	shotCoolTime -= 1;
	if (shotCoolTime <= 0) {
		for(int i = 0;i < n;i ++){
			double angle = CRandom::getInstance()->getRandom() * M_PI * 2;
			 CGameManager::pEnemyBulletManager->addObject(
				this->pEBFtr->create(o->getX(),o->getY(),
					std::make_shared<CStraightMove>(cos(angle) * speed, sin(angle) * speed)
					,10)
			
			);
		}
		shotCoolTime = MAX_COOL_TIME;
	}
}

CRandomEnemyWeapon::~CRandomEnemyWeapon()
{
}
