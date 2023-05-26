#include "CCircle2BossBehavior.h"



CCircle2BossBehavior::CCircle2BossBehavior()
{
	// move
	int const MOVE_TIME = 200;
	int const INTERVAL_TIME = 200;
	this->pMove = std::make_shared<CRandomFlyMove>(MOVE_TIME, INTERVAL_TIME);

	// weapon
	//  moving
	double const M_SPEED = 5.;
	double const M_DIFFUSION = 1.;
	int const M_MAX_COOL_TIME = 5;
	this->pMovingWeapon = std::make_shared<CSpreadEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(), M_SPEED, M_DIFFUSION, M_MAX_COOL_TIME);

	//  waiting
	double const W_SPEED = 5;
	int const W_MAX_COOL_TIME = 5;
	int const W_N = 16;
	this->pWaitingWeapon = std::make_shared<CCircleEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(), W_SPEED, W_MAX_COOL_TIME, W_N);
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
