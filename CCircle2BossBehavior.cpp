#include "CCircle2BossBehavior.h"



CCircle2BossBehavior::CCircle2BossBehavior()
{
	this->pMove = std::make_shared<CRandomFlyMove>(200, 100);
	this->pMovingWeapon = std::make_shared<CSpreadEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(), 5, 1, 5);
	this->pWaitingWeapon = std::make_shared<CCircleEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(), 5, 5, 16);
}

void CCircle2BossBehavior::upDate(CBaseBoss* o) {
	this->pMove->move(o);
	switch (this->pMove->getPhase())
	{
	case CRandomFlyMove::ePhase::Moving:
		this->pMovingWeapon->attack(o);
		break;
	case CRandomFlyMove::ePhase::Waiting:
		this->pWaitingWeapon->attack(o);
		break;
	default:
		break;
	}
}


CCircle2BossBehavior::~CCircle2BossBehavior()
{
}
