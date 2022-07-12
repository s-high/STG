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
	};
private:
	CRandomFlyMove::ePhase prevPhase;
	std::shared_ptr<CBaseEnemyWeapon> pWeapon;
	std::shared_ptr<CRandomFlyMove> pMove;

	void setWeapon();
public:
	CCircle1BossBehavior();
	void upDate(CBaseBoss*) override;
	~CCircle1BossBehavior();
};

