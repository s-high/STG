#pragma once
#include "CBaseObject.h"

class CBaseOutOfScreen
{
public:
	CBaseOutOfScreen();
	virtual void checkHitWall(CBaseObject*) = 0;
	~CBaseOutOfScreen();
};

