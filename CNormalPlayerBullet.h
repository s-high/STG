#pragma once
#include "CBasePlayerBullet.h"
#include "CDeleteOutOfScreen.h"
#include "DxLib.h"

class CNormalPlayerBullet : public CBasePlayerBullet
{
	std::shared_ptr<CBaseOutOfScreen> pOutScreen;
public:
	CNormalPlayerBullet(double, double, std::shared_ptr<CBaseMove>, int);
	void upDate() override;
	void render() override;
	void init() override;
	
	~CNormalPlayerBullet();
};

