#pragma once
#include "CBaseBossBehavior.h"
#include "CReflectMove.h"
#include "CBaseEnemyWeapon.h"

class CHexagon1BossBehavior :
	public CBaseBossBehavior
{
	std::shared_ptr<CReflectMove> pRMove;
	std::shared_ptr<CBaseEnemyWeapon> pWeapon;
	enum ePhase {
		SpawnEnemy,
		Shot,
		Move,
	};
	ePhase currnetPhase;
	int elapsedTime;
	int const SHOT_TIME_MAX = 120;
	int const MOVE_TIME_MAX = 90;
public:
	CHexagon1BossBehavior();
	void upDate(CBaseBoss*) override;
	void setAction();
	~CHexagon1BossBehavior();
};

