#include "CHexagon1BossBehavior.h"
#include "CGameManager.h"


CHexagon1BossBehavior::CHexagon1BossBehavior() {
	this->pRMove = std::make_shared<CReflectMove>(3, 3);

	double const SPEED = 5.;
	int const MAX_COOL_TIME = 2;
	int const N = 8;
	double const INCREACE_ANGLE = 0.2;

	this->pWeapon = std::make_shared<CCircleEnemyWeapon>(
		std::make_shared<CNormalEnemyBulletFactory>(),
		SPEED, MAX_COOL_TIME, N, INCREACE_ANGLE
		);
	this->elapsedTime = this->MOVE_TIME_MAX;
	this->currnetPhase = ePhase::Move;
}

void CHexagon1BossBehavior::upDate(CBaseBoss* o) {
	this->elapsedTime -= 1;
	switch (this->currnetPhase) {
		case CHexagon1BossBehavior::SpawnEnemy:
			CGameManager::pEnemyManager->addObject(
				std::make_shared<CNormalEnemy>(o->getX(), o->getY(), this->E_HP, std::make_shared<CHexagonEnemyGraphic>()
					, std::make_shared<CCircleEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(),
					this->EB_SPEED, this->EB_MAX_COOL_TIME, this->EB_N, this->EB_INCREACE_ANGLE
					), std::make_shared<CReflectMove>(-this->pRMove->getVX(), -this->pRMove->getVY())
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
	int const PROBABILITY_THRESHOLD = 0.3;
	if (r <= PROBABILITY_THRESHOLD) {
		this->currnetPhase = ePhase::Shot;
		this->elapsedTime = this->SHOT_TIME_MAX;
	} else {
		this->currnetPhase = ePhase::SpawnEnemy;
	}
}

CHexagon1BossBehavior::~CHexagon1BossBehavior() {
}
