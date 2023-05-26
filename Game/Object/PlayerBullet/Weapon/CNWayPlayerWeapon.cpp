#include "CNWayPlayerWeapon.h"



CNWayPlayerWeapon::CNWayPlayerWeapon(std::shared_ptr<CObjectManager> pPBMgr, std::shared_ptr<CBasePlayerBulletFactory> pPBFtr, int N) : CBasePlayerWeapon(pPBMgr) {
	this->N = N;
	this->pPBFtr = pPBFtr;
	this->shotCoolTime = 0;
}

void CNWayPlayerWeapon::attack(CBaseObject* o) {
	this->shotCoolTime -= 1;
	if (this->shotCoolTime <= 0) {
		if (N == 1)return;
		double angle = (M_PI * 0.5 - START_ANGLE) * 2 / (N - 1);
		for (int i = 0;i < N;i++) {
			this->pPBMgr->addObject(
				pPBFtr->create(o->getX(), o->getY() - 16,
				std::make_shared<CStraightMove>(
				cos(angle * i + this->START_ANGLE) * this->SPEED,
				-sin(angle * i + this->START_ANGLE) * this->SPEED
			)
				, 10)
			);
		}
		shotCoolTime = this->MAX_COOL_TIME;
	}
}

CNWayPlayerWeapon::~CNWayPlayerWeapon() {
}
