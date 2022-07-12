#pragma once
#include "CBaseBossBehavior.h"
#include "CRandomFlyMove.h"
#include "CSpreadEnemyWeapon.h"
#include "CCircleEnemyWeapon.h"
#include <vector>

class CCircle5BossBehavior :
	public CBaseBossBehavior
{
	std::shared_ptr<CRandomFlyMove> pRFMove;
	
	std::vector<std::shared_ptr<CBaseEnemyWeapon>> moveWeaponVector;
	std::vector<std::shared_ptr<CBaseEnemyWeapon>> waitWeaponVector;
	bool changeFlag, prevChangeFlag;
public:
	CCircle5BossBehavior();
	void upDate(CBaseBoss*) override;
	~CCircle5BossBehavior();
};

