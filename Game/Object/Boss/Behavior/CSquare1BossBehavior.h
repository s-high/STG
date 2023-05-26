#pragma once
#include "CBaseBossBehavior.h"
#include "CGoToMove.h"
#include "extern.h"
#include "CRandomEnemyWeapon.h"

class CSquare1BossBehavior :
	public CBaseBossBehavior
{
	enum ePhase {
		SpawnEnemy,
		ShotSpread,
	};
	ePhase currentPhase;

	int elapsedTime;
	std::shared_ptr<CGoToMove> pGoToMove;
	std::shared_ptr<CBaseEnemyWeapon> pWeapon;
	int const SHOT_TIME = 60;
	int const GO_TO_START_TIME = 60;
	int const SPAWN_TIME = 200;
	int const BACK_TIME = 60;
	
	//  spawn enemy
	void spawnEnemy(double,double);
public:
	CSquare1BossBehavior();
	void upDate(CBaseBoss*) override;
	void setPhase(CBaseBoss*);
	~CSquare1BossBehavior();
};

