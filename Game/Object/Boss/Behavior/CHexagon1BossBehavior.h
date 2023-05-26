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

	// enemy HP
	int const E_HP = 60;

	// enemy weap param
	double const EB_SPEED = 5.;
	int const EB_MAX_COOL_TIME = 60;
	int const EB_N = 2;
	double const EB_INCREACE_ANGLE = M_PI_2;

public:
	CHexagon1BossBehavior();
	void upDate(CBaseBoss*) override;
	void setAction();
	~CHexagon1BossBehavior();
};

