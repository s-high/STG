#include "CCircle3BossBehavior.h"
#include "CCircleEnemyWeapon.h"
#include "CNormalEnemyBulletFactory.h"

CCircle3BossBehavior::CCircle3BossBehavior()
{
	this->currentPhase = ePhase::Wait;
	this->elapsedTime = 0;
	this->setPhase();
	
}

void CCircle3BossBehavior::upDate(CBaseBoss* o) {
	this->elapsedTime -= 1;
	if(this->pWeapon)this->pWeapon->attack(o);
	if (this->elapsedTime <= 0)this->setPhase();
}

void CCircle3BossBehavior::setPhase() {
	this->pWeapon = nullptr;

	switch (this->currentPhase) {
	case ePhase::Shot:
		this->currentPhase = ePhase::Wait;
		this->elapsedTime = this->WAIT_TIME_MAX;
		break;
	case ePhase::Wait:
		double r = CRandom::getInstance()->getRandom();

		if (r <= 0.5) {
			this->speed = 4.;
			this->MAX_COOL_TIME = 1;
			this->n = 1;
			this->increaceAngle = 0.3;
		}
		else if (r <= 0.75) {
			this->speed = 5.;
			this->MAX_COOL_TIME = 2;
			this->n = 4;
			this->increaceAngle = 0.4;
		}
		else {
			this->speed = 5.;
			this->MAX_COOL_TIME = 2;
			this->n = 4;
			this->increaceAngle = 0.2;
		}

		this->pWeapon = std::make_shared<CCircleEnemyWeapon>(
			std::make_shared<CNormalEnemyBulletFactory>(), 
			this->speed, this->MAX_COOL_TIME, this->n, this->increaceAngle
			);

		this->elapsedTime = this->SHOT_TIME_MAX;
		this->currentPhase = ePhase::Shot;
		break;
	}
}

CCircle3BossBehavior::~CCircle3BossBehavior()
{
}
