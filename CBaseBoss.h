#pragma once
#include "CBaseObject.h"
#include "CBossHP.h"
#include "CAppearanceMove.h"

class CBaseBoss :
	public CBaseObject
{
protected:
	std::shared_ptr<CBossHP> pHP;
public:
	CBaseBoss(double,double,int);
	void dispatch(std::shared_ptr<CBaseObject>) override;
	void hitObject(CBasePlayerBullet*) override;
	std::shared_ptr<CBossHP> getHP();
	~CBaseBoss();
};

