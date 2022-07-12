#pragma once
#include "CBaseMove.h"
class CGoToMove :
	public CBaseMove
{
	double vx, vy;
	int time;
public:
	enum eState{
		Moving,
		End,
	};
private:
	eState currentState;
public:
	CGoToMove(CBaseObject*, double, double, double);
	CGoToMove(CBaseObject*, double, double, int);
	void move(CBaseObject*) override;
	eState getState();
	~CGoToMove();
};

