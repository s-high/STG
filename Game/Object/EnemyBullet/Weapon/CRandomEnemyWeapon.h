#pragma once
#include "CBaseEnemyWeapon.h"
#include "CStraightMove.h"

class CRandomEnemyWeapon :
	public CBaseEnemyWeapon
{
	double speed;
	int MAX_COOL_TIME;
	int shotCoolTime;
	int n;
public:
	CRandomEnemyWeapon(std::shared_ptr<CBaseEnemyBulletFactory>, double, int, int);
	void attack(CBaseObject*);
	~CRandomEnemyWeapon();
};

