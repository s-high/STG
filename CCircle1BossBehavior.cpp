#include "CCircle1BossBehavior.h"
#include "CNormalEnemyBulletFactory.h"
#include "CRandomEnemyWeapon.h"

CCircle1BossBehavior::CCircle1BossBehavior()
{
	this->pMove = std::make_shared<CRandomFlyMove>(100,150);
}

void CCircle1BossBehavior::upDate(CBaseBoss* o) {
	//printfDx("%d\n", this->pMove->getPhase());
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
	eWeapon nextWeapon = eWeapon(CRandom::getInstance()->getRandom(2));
	this->pWeapon.reset();
	switch (nextWeapon) {
	case ShotCircle:
		this->pWeapon = std::make_shared<CCircleEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(), 5, 5, 12);
		break;
	case ShotSpread:
		this->pWeapon = std::make_shared<CRandomEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(), 5, 4, 1);
		break;
	case ShotTurnCircle:
		this->pWeapon = std::make_shared<CCircleEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(), 5, 15, 6, CRandom::getInstance()->getRandom() - 0.5);
		break;
	default:
		printfDx("ERROR No Such Weapon %d", nextWeapon);
		break;
	}
}

CCircle1BossBehavior::~CCircle1BossBehavior()
{
}
