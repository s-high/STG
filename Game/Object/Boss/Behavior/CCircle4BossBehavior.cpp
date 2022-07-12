#include "CCircle4BossBehavior.h"
#include "CNormalEnemyBulletFactory.h"


CCircle4BossBehavior::CCircle4BossBehavior()
{
	this->pRFMove = std::make_shared<CRandomFlyMove>(60,30);
	//this->pCircleWeapon = std::make_shared<CCircleEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(), 5, 2, 12, 0.2);
	this->pCircleWeapon = std::make_shared<CCircleEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(), 5, 2, 12);
	this->pSpreadWeapon = std::make_shared<CSpreadEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(), 5, 0.6, 8, 1);
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
