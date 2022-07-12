#pragma once
#include "CBaseOutOfScreen.h"
#include "extern.h"

class CDeleteOutOfScreen :
	public CBaseOutOfScreen
{
public:
	CDeleteOutOfScreen();
	void checkHitWall(CBaseObject*);
	~CDeleteOutOfScreen();
};

