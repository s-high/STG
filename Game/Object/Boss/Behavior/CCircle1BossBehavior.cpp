#include "CCircle1BossBehavior.h"
#include "CNormalEnemyBulletFactory.h"
#include "CRandomEnemyWeapon.h"

CCircle1BossBehavior::CCircle1BossBehavior()
{
	int const MOVE_TIME = 100;
	int const INTERVAL_TIME = 150;
	this->pMove = std::make_shared<CRandomFlyMove>(MOVE_TIME,INTERVAL_TIME);

	// init
	//  ShotCircle
	this->SC_SPEED = 5;
	this->SC_MAX_COOL_TIME = 5;
	this->SC_N = 12;
	//  ShotSpread
	this->SS_SPEED = 5;
	this->SS_MAX_COOL_TIME = 4;
	this->SS_N = 1;
	//  ShotTurnCircle
	this->STC_SPEED = 5;
	this->STC_MAX_COOL_TIME = 15;
	this->STC_N = 6;
	this->STC_INCREACE_ANGLE = CRandom::getInstance()->getRandom() - 0.5;
}

void CCircle1BossBehavior::upDate(CBaseBoss* o) {
	this->pMove->move(o);
	switch (this->pMove->getPhase())
	{
	case CRandomFlyMove::ePhase::Moving:
		this->prevPhase = CRandomFlyMove::ePhase::Moving;
		break;
	case CRandomFlyMove::ePhase::Waiting:
		if (this->prevPhase == CRandomFlyMove::ePhase::Moving) {
			this->setWeapon();
		}
		this->pWeapon->attack(o);
		this->prevPhase = CRandomFlyMove::ePhase::Waiting;
		break;
	default:
		break;
	}
}

void CCircle1BossBehavior::setWeapon() {
	eWeapon nextWeapon = eWeapon(CRandom::getInstance()->getRandom(int(eWeapon::NumWeapons) - 1));
	this->pWeapon.reset();
	switch (nextWeapon) {
	case ShotCircle:
		this->pWeapon = std::make_shared<CCircleEnemyWeapon>(
			std::make_shared<CNormalEnemyBulletFactory>(), 
			this->SC_SPEED, this->SC_MAX_COOL_TIME, this->SC_N
			);
		break;
	case ShotSpread:
		this->pWeapon = std::make_shared<CRandomEnemyWeapon>(
			std::make_shared<CNormalEnemyBulletFactory>(), 
			this->SS_SPEED, this->SS_MAX_COOL_TIME, this->SS_N
			);
		break;
	case ShotTurnCircle:
		this->STC_INCREACE_ANGLE = CRandom::getInstance()->getRandom() - 0.5;
		this->pWeapon = std::make_shared<CCircleEnemyWeapon>(
			std::make_shared<CNormalEnemyBulletFactory>(), 
			this->STC_SPEED, this->STC_MAX_COOL_TIME, this->STC_N, this->STC_INCREACE_ANGLE
			);
		break;
	default:
		printfDx("ERROR No Such Weapon %d", nextWeapon);
		break;
	}
}

CCircle1BossBehavior::~CCircle1BossBehavior()
{
}
