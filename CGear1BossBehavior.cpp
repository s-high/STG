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
	this->pWeapon = std::make_shared<CRandomEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(), 5, 4, 1);
	this->pMove = std::make_shared<CRandomFlyMove>(30, 1);
	this->elapsedTime = 0;

	/*
	this->pRFMove = std::make_shared<CRandomFlyMove>(30,0);
	
	std::shared_ptr<CCircleEnemyShot> pShot = std::make_shared<CCircleEnemyShot>(std::make_shared<CNormalEnemyBulletFactory>(), 5, 8, 0);
	std::shared_ptr<CExplodeEnemyBulletFactory> pFtr = std::make_shared<CExplodeEnemyBulletFactory>(40,pShot);
	this->pWeapon = std::make_shared<CSpreadEnemyWeapon>(pFtr, 3, 0.05, 60 ,1);
	*/
}

void CGear1BossBehavior::upDate(CBaseBoss* o) {
	switch (this->currentPhase)
	{
	case ePhase::RandomMove:
		this->pWeapon->attack(o);
		this->pMove->move(o);
		if(this->RANDOM_MOVE_MAX <= this->elapsedTime){
			this->currentPhase = ePhase::GoToMove;
			this->elapsedTime = 0;
		}
		break;
	case ePhase::GoToMove:
		this->pWeapon->attack(o);
		this->pMove->move(o);
		if (this->elapsedTime <= GTM_START_TIME) {
			if (this->elapsedTime == GTM_START_TIME) {
				this->pMove = std::make_shared<CGoToMove>(o, SCREEN_WIDTH - 100, 100, int(GTM_SPAWN_TIME));
			}
		}
		else if (this->elapsedTime <= GTM_START_TIME + GTM_SPAWN_TIME) {
			if (this->elapsedTime == GTM_START_TIME + GTM_SPAWN_TIME) {
				this->pMove = std::make_shared<CGoToMove>(o, SCREEN_WIDTH * 0.5, 250, int(GTM_BACK_TIME));
			}
		}
		else {
			if (this->elapsedTime == GTM_START_TIME + GTM_SPAWN_TIME + GTM_BACK_TIME) {
				setPhase(o);
			}
		}
		break;
	}
	this->elapsedTime += 1;
}

void CGear1BossBehavior::setPhase(CBaseBoss* o) {
	this->elapsedTime = 0;
	if (CRandom::getInstance()->getRandom() < 0.7) {
		this->currentPhase = ePhase::GoToMove;
		this->pMove = std::make_shared<CGoToMove>(o, 100, 100, int(GTM_START_TIME));
		this->pWeapon = std::make_shared<CSpreadEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(), 5, 0.2, 7, 1);
	}
	else {
		this->currentPhase = ePhase::RandomMove;
		this->pWeapon = std::make_shared<CRandomEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(), 5, 4, 1);
		this->pMove = std::make_shared<CRandomFlyMove>(30, 1);
	}
}

CGear1BossBehavior::~CGear1BossBehavior()
{
}
