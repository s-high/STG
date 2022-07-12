#pragma once
#include "CBaseBoss.h"
#include "CBossGraphic.h"

class CDisplayBoss :
	public CBaseBoss
{
	std::shared_ptr<CBaseBossGraphic> pGraphic;
public:
	CDisplayBoss(double, double, std::shared_ptr<CBaseBossGraphic>);
	void upDate() override;
	void render() override;
	void init() override;
	void finalize() override;
	//void hitObject(CBasePlayerBullet*) override;
	~CDisplayBoss();
};

