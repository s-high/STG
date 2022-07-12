#pragma once
#include "CBaseEnemyBulletFactory.h"
#include "CObjectManager.h"
#include "CBaseBoss.h"

class CBaseEnemyWeapon
{
protected:
	std::shared_ptr<CBaseEnemyBulletFactory> pEBFtr;
public:
	CBaseEnemyWeapon(std::shared_ptr<CBaseEnemyBulletFactory>);
	virtual void attack(CBaseObject*) = 0;
	void attack(CBaseBoss*);
	~CBaseEnemyWeapon();
};

