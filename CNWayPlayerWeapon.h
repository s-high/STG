#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "CBasePlayerWeapon.h"
#include "CBasePlayerBulletFactory.h"
#include "CStraightMove.h"

class CNWayPlayerWeapon :
	public CBasePlayerWeapon
{
	const int MAX_COOL_TIME = 10;
	const double START_ANGLE = M_PI * 0.4;
	const double SPEED = 5;

	int N;
	int shotCoolTime;
	std::shared_ptr<CBasePlayerBulletFactory> pPBFtr;

public:
	CNWayPlayerWeapon(std::shared_ptr<CObjectManager> pPBMgr, std::shared_ptr<CBasePlayerBulletFactory>,int);
	void attack(CBaseObject*);
	~CNWayPlayerWeapon();
};

