#pragma once
#include "CBaseObject.h"

class CBaseBossBehavior
{
public:
	CBaseBossBehavior();
	virtual void upDate(CBaseBoss*) = 0;
	~CBaseBossBehavior();
};

