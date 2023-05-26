#pragma once
#include "CBaseBossBehavior.h"
#include "CBaseEnemyWeapon.h"
#include <vector>

class CCircle3BossBehavior :
	public CBaseBossBehavior
{
	enum ePhase {
		Shot,
		Wait,
	};
	ePhase currentPhase;
	int elapsedTime;
	int const SHOT_TIME_MAX = 180;
	int const WAIT_TIME_MAX = 60;

	// weapon param
	double speed;
	int MAX_COOL_TIME;
	int n;
	double increaceAngle;

	std::shared_ptr<CBaseEnemyWeapon> pWeapon;
public:
	CCircle3BossBehavior();
	void upDate(CBaseBoss*) override;
	void setPhase();
	~CCircle3BossBehavior();
};

