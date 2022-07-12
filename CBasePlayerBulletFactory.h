#pragma once
#include "CBasePlayerBullet.h"

class CBasePlayerBulletFactory
{
public:
	CBasePlayerBulletFactory();
	virtual std::shared_ptr<CBasePlayerBullet> create(double, double, std::shared_ptr<CBaseMove>, int) = 0;
	~CBasePlayerBulletFactory();
};

