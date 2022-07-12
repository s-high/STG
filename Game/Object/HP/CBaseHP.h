#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

class CBaseHP
{
	int maxHP;
	int hp;
public:
	CBaseHP(int);
	void addDamage(int);
	int getHP();
	double getPercent();
	virtual void render(double,double) = 0;
	~CBaseHP();
};

