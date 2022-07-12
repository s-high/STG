#pragma once
#include "CBaseObject.h"
class CBaseMove
{
public:
	CBaseMove();
	virtual void move(CBaseObject*) = 0;
	void move(CBaseBoss*);
	~CBaseMove();
};

