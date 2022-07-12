#include "CSquare1BossBehavior.h"
#include "CGameManager.h"

CSquare1BossBehavior::CSquare1BossBehavior()
{
	this->currentPhase = ePhase::ShotSpread;
	this->pWeapon = std::make_shared<CRandomEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(), 5, 4, 1);
	this->elapsedTime = 0;
}

void CSquare1BossBehavior::upDate(CBaseBoss* o) {
	//printfDx("p : %d  e : %d\n", currentPhase, elapsedTime);
	switch (this->currentPhase)
	{
	case ePhase::ShotSpread:
		this->pWeapon->attack(o);
		if (60 <= this->elapsedTime) {
			setPhase(o);
		}
		break;
	case ePhase::SpawnEnemy:
		if (this->elapsedTime <= GO_TO_START_TIME) {
			this->pGoToMove->move(o);

			if (this->elapsedTime == GO_TO_START_TIME) {
				this->pGoToMove = std::make_shared<CGoToMove>(o,SCREEN_WIDTH - 100, 100, int(SPAWN_TIME));
			}
		}
		else if(this->elapsedTime <= GO_TO_START_TIME + SPAWN_TIME){
			this->pGoToMove->move(o);

			//spawn
			if (CRandom::getInstance()->getRandom() < 0.005) {
				CGameManager::pEnemyManager->addObject(
					std::make_shared<CNormalEnemy>(o->getX(), o->getY(), 60, std::make_shared<CSquareEnemyGraphic>()
							,std::make_shared<CCircleEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(),5, 60, 4,M_PI_4
								),std::make_shared<CStraightMove>(0,0)
						)
				);
			}

			if (this->elapsedTime == GO_TO_START_TIME + SPAWN_TIME) {
				this->pGoToMove = std::make_shared<CGoToMove>(o,SCREEN_WIDTH * 0.5, 250, int(BACK_TIME));
			}
		}
		else if (this->elapsedTime <= GO_TO_START_TIME + SPAWN_TIME + BACK_TIME) {
			this->pGoToMove->move(o);

			if (this->elapsedTime == GO_TO_START_TIME + SPAWN_TIME + BACK_TIME) {
				setPhase(o);
			}
		}

		break;
	default:
		break;
	}
	this->elapsedTime += 1;
}

void CSquare1BossBehavior::setPhase(CBaseBoss* o) {
	this->elapsedTime = 0;
	if (CRandom::getInstance()->getRandom() < 0.7) {
		this->currentPhase = ePhase::SpawnEnemy;
		this->pGoToMove = std::make_shared<CGoToMove>(o,100, 100, int(GO_TO_START_TIME));
	}
	else {
		this->currentPhase = ePhase::ShotSpread;
		this->pWeapon = std::make_shared<CRandomEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(), 5, 4, 1);
	}
}


CSquare1BossBehavior::~CSquare1BossBehavior()
{
}
