#pragma once
#include "CBaseOutOfScreen.h"
#include "extern.h"

class CRestrictOutOfScreen :
	public CBaseOutOfScreen
{
public:
	CRestrictOutOfScreen();
	void checkHitWall(CBaseObject*);
	~CRestrictOutOfScreen();
};

