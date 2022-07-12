#pragma once
#include "CBaseMove.h"
#include "extern.h"

class CReflectMove :
	public CBaseMove
{
	double vx, vy;
public:
	CReflectMove(double,double);
	void move(CBaseObject*) override;
	double getVX() const;
	double getVY() const;
	~CReflectMove();
};

