#pragma once
#include "CBaseObject.h"
#include "CObjectManager.h"

class CBasePlayerWeapon
{
protected:
	std::shared_ptr<CObjectManager> pPBMgr;
public:
	CBasePlayerWeapon(std::shared_ptr<CObjectManager>);
	virtual void attack(CBaseObject*) = 0;
	~CBasePlayerWeapon();
};

