#include "CCircle3BossBehavior.h"
#include "CCircleEnemyWeapon.h"
#include "CNormalEnemyBulletFactory.h"

CCircle3BossBehavior::CCircle3BossBehavior()
{
	this->currentPhase = ePhase::Wait;
	this->setPhase();
}

void CCircle3BossBehavior::upDate(CBaseBoss* o) {
	this->elapsedTime -= 1;
	for (auto e : this->pWeaponVector)e->attack(o);
	if (this->elapsedTime <= 0)this->setPhase();
}

void CCircle3BossBehavior::setPhase() {
	this->pWeaponVector.clear();

	switch (this->currentPhase) {
	case ePhase::Shot:
		this->currentPhase = ePhase::Wait;
		this->elapsedTime = this->WAIT_TIME_MAX;
		break;
	case ePhase::Wait:
		double r = CRandom::getInstance()->getRandom();

		if (r <= 0.5) {
			this->pWeaponVector.push_back(std::make_shared<CCircleEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(), 4, 1, 1, 0.3));
			//this->pWeaponVector.push_back(std::make_shared<CCircleEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(), 4, 1, 1, -0.3));
		}
		else if(r <= 0.75){
			this->pWeaponVector.push_back(std::make_shared<CCircleEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(), 5, 2, 4, 0.4));
		}
		else {
			this->pWeaponVector.push_back(std::make_shared<CCircleEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(), 5, 2, 4, 0.2));
			//this->pWeaponVector.push_back(std::make_shared<CCircleEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(), 5, 2, 4, -0.2));
		}
		this->elapsedTime = this->SHOT_TIME_MAX;
		this->currentPhase = ePhase::Shot;
		break;
	}
}

CCircle3BossBehavior::~CCircle3BossBehavior()
{
}
