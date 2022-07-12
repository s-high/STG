#pragma once
#include "CBaseBossBehavior.h"
#include "CRandomFlyMove.h"
#include "CSpreadEnemyWeapon.h"
#include "CCircleEnemyWeapon.h"

class CCircle4BossBehavior :
	public CBaseBossBehavior
{
	std::shared_ptr<CRandomFlyMove> pRFMove;
	std::shared_ptr<CSpreadEnemyWeapon> pSpreadWeapon;
	std::shared_ptr<CCircleEnemyWeapon> pCircleWeapon;
public:
	CCircle4BossBehavior();
	void upDate(CBaseBoss*) override;
	~CCircle4BossBehavior();
};

