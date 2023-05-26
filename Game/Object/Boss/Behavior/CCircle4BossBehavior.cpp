#include "CCircle4BossBehavior.h"
#include "CNormalEnemyBulletFactory.h"


CCircle4BossBehavior::CCircle4BossBehavior()
{
	// move
	int const MOVE_TIME = 60;
	int const INTERVAL_TIME = 30;
	this->pRFMove = std::make_shared<CRandomFlyMove>(MOVE_TIME,INTERVAL_TIME);

	// weapon
	//  circle
	double const C_SPEED = 5;
	int const C_MAX_COOL_TIME = 2;
	int const C_N = 12;
	this->pCircleWeapon = std::make_shared<CCircleEnemyWeapon>(
		std::make_shared<CNormalEnemyBulletFactory>(), 
		C_SPEED, C_MAX_COOL_TIME, C_N
		);

	//  spread
	double const S_SPREAD = 5.;
	double const S_DIFFUSION = 0.6;
	int const S_MAX_COOL_TIME = 8;
	int const S_N = 1;
	this->pSpreadWeapon = std::make_shared<CSpreadEnemyWeapon>(
		std::make_shared<CNormalEnemyBulletFactory>(),
		S_SPREAD, S_DIFFUSION, S_MAX_COOL_TIME, S_N
		);
}

void CCircle4BossBehavior::upDate(CBaseBoss* o) {
	pRFMove->move(o);
	switch (this->pRFMove->getPhase())
	{
	case CRandomFlyMove::ePhase::Moving:
		this->pSpreadWeapon->attack(o);

		break;
	case CRandomFlyMove::ePhase::Waiting:
		this->pCircleWeapon->attack(o);
		
		break;
	default:
		break;
	}
}

CCircle4BossBehavior::~CCircle4BossBehavior()
{
}
