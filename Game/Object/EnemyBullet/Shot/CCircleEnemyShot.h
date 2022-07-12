#pragma once
#include "CBaseEnemyShot.h"
#include "CStraightMove.h"
#include "CGameManager.h"

class CCircleEnemyShot :
	public CBaseEnemyShot
{
	double speed;
	int n;
	double initAngle;
public:
	CCircleEnemyShot(std::shared_ptr<CBaseEnemyBulletFactory>,double,int,double);
	void shot(CBaseObject*);
	void shot(double, double);
	void setInitAngle(double);
	double getInitAngle();
	~CCircleEnemyShot();
};

