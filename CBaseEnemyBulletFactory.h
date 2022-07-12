#pragma once
#include "CBaseEnemyBullet.h"

class CBaseEnemyBulletFactory
{
public:
	CBaseEnemyBulletFactory();
	virtual std::shared_ptr<CBaseEnemyBullet> create(double, double, std::shared_ptr<CBaseMove>, int) = 0;
	~CBaseEnemyBulletFactory();
};

