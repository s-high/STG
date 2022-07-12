#pragma once
#include "CBaseMove.h"
#include "CEnemyGraphic.h"

class CBaseEnemyFactory
{
public:
	CBaseEnemyFactory();
	virtual std::shared_ptr<CBaseMove>  createMove() = 0;
	~CBaseEnemyFactory();
};

