#pragma once
#include "CBaseBossBehavior.h"
#include "CRandom.h"

#include "CBaseEnemyWeapon.h"
#include "CCircleEnemyWeapon.h"
#include "CSpreadEnemyWeapon.h"
#include "CRandomFlyMove.h"

class CCircle1BossBehavior :
	public CBaseBossBehavior
{
public:
	enum eWeapon {
		ShotCircle = 0,
		ShotSpread = 1,
		ShotTurnCircle = 2,
		NumWeapons = 3,
	};
private:
	CRandomFlyMove::ePhase prevPhase;
	std::shared_ptr<CBaseEnemyWeapon> pWeapon;
	std::shared_ptr<CRandomFlyMove> pMove;

	void setWeapon();

	// ShotCircle
	double SC_SPEED;
	int SC_MAX_COOL_TIME,SC_N;

	// ShotSpread
	double SS_SPEED;
	int SS_MAX_COOL_TIME, SS_N;

	// ShotTurnCircle
	double STC_SPEED,STC_INCREACE_ANGLE;
	int STC_MAX_COOL_TIME, STC_N;
public:
	CCircle1BossBehavior();
	void upDate(CBaseBoss*) override;
	~CCircle1BossBehavior();
};

