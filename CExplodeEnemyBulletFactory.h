#pragma once
#include "CBaseEnemyBulletFactory.h"
#include "CBaseEnemyShot.h"
#include "CExplodeEnemyBullet.h"

class CExplodeEnemyBulletFactory :
	public CBaseEnemyBulletFactory
{
	std::shared_ptr<CBaseEnemyShot> pShot;
	int life;
public:
	CExplodeEnemyBulletFactory(int, std::shared_ptr<CBaseEnemyShot>);
	std::shared_ptr<CBaseEnemyBullet> create(double, double, std::shared_ptr<CBaseMove>, int) override;
	~CExplodeEnemyBulletFactory();
};

