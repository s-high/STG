#pragma once
#include "CBaseObject.h"
#include "CBaseMove.h"
#include "CCircle.h"

class CBaseEnemyBullet :
	public CBaseObject
{
protected:
	int damage;
	std::shared_ptr<CBaseMove> pMove;
public:
	CBaseEnemyBullet(double,double,std::shared_ptr<CBaseMove>,int);
	~CBaseEnemyBullet();
	void dispatch(std::shared_ptr<CBaseObject>);
};

