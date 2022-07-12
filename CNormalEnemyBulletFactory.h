#pragma once
#include "CBaseEnemyBulletFactory.h"
#include "CNormalEnemyBullet.h"

class CNormalEnemyBulletFactory :
	public CBaseEnemyBulletFactory
{
public:
	CNormalEnemyBulletFactory();
	std::shared_ptr<CBaseEnemyBullet> create(double, double, std::shared_ptr<CBaseMove>, int) override;
	~CNormalEnemyBulletFactory();
};

