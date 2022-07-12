#pragma once
#include "CBasePlayerBulletFactory.h"
#include "CNormalPlayerBullet.h"

class CNormalPlayerBulletFactory :
	public CBasePlayerBulletFactory
{
public:
	CNormalPlayerBulletFactory();
	std::shared_ptr<CBasePlayerBullet> create(double, double, std::shared_ptr<CBaseMove>, int);
	~CNormalPlayerBulletFactory();
};

