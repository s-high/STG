#pragma once
#include "CBaseBossBehavior.h"
#include "CRandomFlyMove.h"
#include "CBaseEnemyWeapon.h"

class CGear1BossBehavior :
	public CBaseBossBehavior
{
	enum ePhase {
		RandomMove,
		GoToMove,
	};
	ePhase currentPhase;
	int elapsedTime;
	int const RANDOM_MOVE_MAX = 120;
	int const GTM_START_TIME = 60;
	int const GTM_SPAWN_TIME = 200;
	int const GTM_BACK_TIME = 60;

	std::shared_ptr<CBaseMove> pMove;
	std::shared_ptr<CBaseEnemyWeapon> pWeapon;
public:
	CGear1BossBehavior();
	void upDate(CBaseBoss*) override;
	void setPhase(CBaseBoss*);
	~CGear1BossBehavior();
};

