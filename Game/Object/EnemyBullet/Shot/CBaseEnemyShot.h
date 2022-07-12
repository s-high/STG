#pragma once
#include "CBaseEnemyBulletFactory.h"
#include "CObjectManager.h"

class CBaseEnemyShot
{
protected:
	std::shared_ptr<CBaseEnemyBulletFactory> pEBFtr;
public:
	CBaseEnemyShot(std::shared_ptr<CBaseEnemyBulletFactory>);
	virtual void shot(CBaseObject*) = 0;
	virtual void shot(double, double) = 0;
	~CBaseEnemyShot();
};

