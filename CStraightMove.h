#pragma once
#include "CBaseMove.h"
class CStraightMove :
	public CBaseMove
{
	double vx, vy;
public:
	CStraightMove(double, double);
	void move(CBaseObject*);
	~CStraightMove();
};

