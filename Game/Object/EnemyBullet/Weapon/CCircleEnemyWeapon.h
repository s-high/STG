#pragma once
#include "CBaseEnemyWeapon.h"
#include "CObjectManager.h"


class CCircleEnemyShot;

class CCircleEnemyWeapon :
	public CBaseEnemyWeapon
{
	std::shared_ptr<CCircleEnemyShot> pCircleShot;
	int MAX_COOL_TIME;
	int shotCoolTime;
	double increaseAngle;
public:
	CCircleEnemyWeapon(std::shared_ptr<CBaseEnemyBulletFactory>, double, int, int);
	CCircleEnemyWeapon(std::shared_ptr<CBaseEnemyBulletFactory>, double, int, int, double);
	void attack(CBaseObject*);
	~CCircleEnemyWeapon();
};

