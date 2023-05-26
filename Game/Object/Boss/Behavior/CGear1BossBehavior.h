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
	int moveTime;

	std::shared_ptr<CRandomFlyMove> pRFM;
	std::shared_ptr<CBaseEnemyWeapon> pWeapon;
public:
	CGear1BossBehavior();
	void upDate(CBaseBoss*) override;
	void setMove();
	~CGear1BossBehavior();
};

