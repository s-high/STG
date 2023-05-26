#include "CGear1BossBehavior.h"
#include "CSpreadEnemyWeapon.h"
#include "CExplodeEnemyBulletFactory.h"
#include "CNormalEnemyBulletFactory.h"
#include "CCircleEnemyShot.h"
#include "CGoToMove.h"
#include "CRandomEnemyWeapon.h"

CGear1BossBehavior::CGear1BossBehavior()
{
	this->currentPhase = ePhase::RandomMove;

	this->setMove();
	
	// weapon
	double const SPEED = 5;
	double const DIFFUSION = 0.8;
	int const MAX_COOL_TIME = 8;
	int const N = 1;
	this->pWeapon = std::make_shared<CSpreadEnemyWeapon>(
		std::make_shared<CNormalEnemyBulletFactory>(), 
		SPEED, DIFFUSION, MAX_COOL_TIME, N
		);
}

void CGear1BossBehavior::upDate(CBaseBoss* o) {
	this->pWeapon->attack(o);
	this->pRFM->move(o);

	if (this->pRFM->getPhase() == CRandomFlyMove::ePhase::Waiting) {
		this->setMove();
	}
	this->elapsedTime += 1;
}

void CGear1BossBehavior::setMove() {
	this->elapsedTime = 0;

	int const RANDOM_MAX = 60;
	int const RANDOM_MIN = 45;
	int const INTERVAL = 1;
	this->moveTime = CRandom::getInstance()->getRandom(RANDOM_MAX, RANDOM_MIN);
	this->pRFM = std::make_shared<CRandomFlyMove>(this->moveTime, INTERVAL);
}

CGear1BossBehavior::~CGear1BossBehavior()
{
}
