#pragma once
#include "CBaseMove.h"
#include "CKeyFacade.h"

class CPlayerMove : public CBaseMove
{
	double speed;
public:
	CPlayerMove(double);
	void move(CBaseObject*);
	~CPlayerMove();
};

