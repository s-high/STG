#include "CCircle5BossBehavior.h"
#include "CNormalEnemyBulletFactory.h"
#include "CNormalBoss.h"

CCircle5BossBehavior::CCircle5BossBehavior()
{
	// move
	int const MOVE_TIME = 120;
	int const INTERVAL_TIME = 240;
	this->pRFMove = std::make_shared<CRandomFlyMove>(MOVE_TIME, INTERVAL_TIME);

	this->moveWeaponVector.push_back(std::make_shared<CSpreadEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(), 5, 0.4, 8, 1));
	this->waitWeaponVector.push_back(std::make_shared<CCircleEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(), 5, 2, 18, 0.01));

	this->changeFlag = false;
	this->prevChangeFlag = false;
}

void CCircle5BossBehavior::upDate(CBaseBoss* o) {
	pRFMove->move(o);
	switch (this->pRFMove->getPhase())
	{
	case CRandomFlyMove::ePhase::Moving:
		for (auto e : this->moveWeaponVector)e->attack(o);

		break;
	case CRandomFlyMove::ePhase::Waiting:
		for (auto e : this->waitWeaponVector)e->attack(o);

		break;
	default:
		break;
	}
	if (!this->prevChangeFlag && this->changeFlag) {
		// clear
		this->moveWeaponVector.clear();
		this->waitWeaponVector.clear();

		// wait
		this->waitWeaponVector.push_back(std::make_shared<CCircleEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(), 5, 2, 16, 0));
		this->waitWeaponVector.push_back(std::make_shared<CSpreadEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(), 5, 0.4, 3, 1));

		// move
		this->moveWeaponVector.push_back(std::make_shared<CSpreadEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(), 5, 0.4, 8, 1));
	}
	this->prevChangeFlag = this->changeFlag;
	if (o->getHP()->getPercent() < 0.5)this->changeFlag = true;
}


CCircle5BossBehavior::~CCircle5BossBehavior()
{
}
