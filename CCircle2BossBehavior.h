#pragma once
#include "CBaseBossBehavior.h"
#include "CRandom.h"

#include "CBaseEnemyWeapon.h"

#include "CCircleEnemyWeapon.h"
#include "CSpreadEnemyWeapon.h"

#include "CRandomFlyMove.h"
#include "CNormalEnemyBulletFactory.h"

class CCircle2BossBehavior :
	public CBaseBossBehavior
{
	std::shared_ptr<CRandomFlyMove> pMove;
	std::shared_ptr<CBaseEnemyWeapon> pMovingWeapon;
	std::shared_ptr<CBaseEnemyWeapon> pWaitingWeapon;
public:
	CCircle2BossBehavior();
	void upDate(CBaseBoss*) override;
	~CCircle2BossBehavior();
};

