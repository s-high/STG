#include "CSquare1BossBehavior.h"
#include "CGameManager.h"

CSquare1BossBehavior::CSquare1BossBehavior() {
	this->currentPhase = ePhase::ShotSpread;
	double const SPEED = 5;
	int const MAX_COOL_TIME = 4;
	int const N = 1;
	this->pWeapon = std::make_shared<CRandomEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(), SPEED, MAX_COOL_TIME, N);
	this->elapsedTime = 0;
}

void CSquare1BossBehavior::upDate(CBaseBoss* o) {
	switch (this->currentPhase) {
		case ePhase::ShotSpread:
			this->pWeapon->attack(o);
			if (this->SHOT_TIME <= this->elapsedTime) {
				setPhase(o);
			}
			break;
		case ePhase::SpawnEnemy:
			if (this->elapsedTime <= this->GO_TO_START_TIME) {
				this->pGoToMove->move(o);

				if (this->elapsedTime == this->GO_TO_START_TIME) {
					this->pGoToMove = std::make_shared<CGoToMove>(o, SCREEN_WIDTH - 100, 100, int(this->SPAWN_TIME));
				}
			} else if (this->elapsedTime <= this->GO_TO_START_TIME + this->SPAWN_TIME) {
				this->pGoToMove->move(o);

				// spawn  enemy
				if (CRandom::getInstance()->getRandom() < 0.005) {
					this->spawnEnemy(o->getX(), o->getY());
				}

				if (this->elapsedTime == this->GO_TO_START_TIME + this->SPAWN_TIME) {
					this->pGoToMove = std::make_shared<CGoToMove>(o, SCREEN_WIDTH * 0.5, 250, int(this->BACK_TIME));
				}
			} else if (this->elapsedTime <= this->GO_TO_START_TIME + this->SPAWN_TIME + this->BACK_TIME) {
				this->pGoToMove->move(o);

				if (this->elapsedTime == this->GO_TO_START_TIME + this->SPAWN_TIME + this->BACK_TIME) {
					setPhase(o);
				}
			}

			break;
		default:
			break;
	}
	this->elapsedTime += 1;
}

void CSquare1BossBehavior::spawnEnemy(double x, double y) {
	// enemy
	int const HP = 60;

	// enemy weapon
	double const SPEED = 5.;
	int const MAX_COOL_TIME = 60;
	int const N = 4;
	double const INCREACE_ANGLE = M_PI_4;

	CGameManager::pEnemyManager->addObject(
		std::make_shared<CNormalEnemy>(x, y, HP, std::make_shared<CSquareEnemyGraphic>()
			, std::make_shared<CCircleEnemyWeapon>(std::make_shared<CNormalEnemyBulletFactory>(), SPEED, MAX_COOL_TIME, N, INCREACE_ANGLE
			), std::make_shared<CStraightMove>(0, 0)
		)
	);
}

void CSquare1BossBehavior::setPhase(CBaseBoss* o) {
	this->elapsedTime = 0;
	double const PROBABILITY_THRESHOLD = 0.7;
	if (CRandom::getInstance()->getRandom() < PROBABILITY_THRESHOLD) {
		this->currentPhase = ePhase::SpawnEnemy;
		int const X = 100;
		int const Y = 100;
		this->pGoToMove = std::make_shared<CGoToMove>(o, X, Y, int(GO_TO_START_TIME));
	} else {
		this->currentPhase = ePhase::ShotSpread;

	}
}


CSquare1BossBehavior::~CSquare1BossBehavior() {
}
