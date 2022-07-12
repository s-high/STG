#pragma once
#include "CBaseEnemyWeapon.h"
#include "CObjectManager.h"

class CSpreadEnemyWeapon :
	public CBaseEnemyWeapon
{
	int MAX_COOL_TIME;
	int shotCoolTime;
	double speed;
	double diffusion;
	int n;
public:
	CSpreadEnemyWeapon(std::shared_ptr<CBaseEnemyBulletFactory>, double, double, int);
	CSpreadEnemyWeapon(std::shared_ptr<CBaseEnemyBulletFactory>, double, double, int, int);
	void attack(CBaseObject* o) override;
	~CSpreadEnemyWeapon();
};

