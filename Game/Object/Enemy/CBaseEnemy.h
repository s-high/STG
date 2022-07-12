#pragma once
#include "CBaseObject.h"
#include "CNormalHP.h"

class CBaseEnemy :
	public CBaseObject
{
protected:
	std::shared_ptr<CNormalHP> pHP;
public:
	CBaseEnemy(double, double,int);
	~CBaseEnemy();
};

