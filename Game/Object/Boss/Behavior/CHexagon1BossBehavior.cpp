#include "CHexagon1BossBehavior.h"
#include "CGameManager.h"


CHexagon1BossBehavior::CHexagon1BossBehavior()
{
	this->pRMove = std::make_shared<CReflectMove>(3, 3);
	//this->pWeapon = std::make_shared<CCircleEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(), 5, 2, 12, 0.2);
	this->pWeapon = std::make_shared<CCircleEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(), 5, 2, 8, 0.2);
	this->elapsedTime = this->MOVE_TIME_MAX;
	this->currnetPhase = ePhase::Move;
}

void CHexagon1BossBehavior::upDate(CBaseBoss* o) {
	this->elapsedTime -= 1;
	switch (this->currnetPhase)
	{
	case CHexagon1BossBehavior::SpawnEnemy:
		CGameManager::pEnemyManager->addObject(
			std::make_shared<CNormalEnemy>(o->getX(), o->getY(), 60, std::make_shared<CHexagonEnemyGraphic>()
				, std::make_shared<CCircleEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(),5, 60, 2, M_PI_2)
				,std::make_shared<CReflectMove>(-this->pRMove->getVX(), -this->pRMove->getVY())
			)
		);

		this->elapsedTime = this->MOVE_TIME_MAX;
		this->currnetPhase = ePhase::Move;
		break;
	case CHexagon1BossBehavior::Shot:
		this->pWeapon->attack(o);
		if (elapsedTime <= 0) {
			this->elapsedTime = this->MOVE_TIME_MAX;
			this->currnetPhase = ePhase::Move;
		}
		break;
	case CHexagon1BossBehavior::Move:
		this->pRMove->move(o);
		if (elapsedTime <= 0)this->setAction();
		break;
	default:
		break;
	}
}

void CHexagon1BossBehavior::setAction() {
	double r = CRandom::getInstance()->getRandom();
	if (r <= 0.3) {
		this->currnetPhase = ePhase::Shot;
		this->elapsedTime = this->SHOT_TIME_MAX;
	}
	else {
		this->currnetPhase = ePhase::SpawnEnemy;
	}
}

CHexagon1BossBehavior::~CHexagon1BossBehavior()
{
}
