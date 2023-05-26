#pragma once
#include "CBaseBoss.h"
#include "CBaseBossBehavior.h"
#include "CBossGraphic.h"

#include "CCircle1BossBehavior.h"

class CNormalBoss :
	public CBaseBoss
{
	std::shared_ptr<CBaseBossGraphic> pGraphic;
	std::shared_ptr<CBaseBossBehavior> pBehavior;
	std::shared_ptr<CAppearanceMove> pAMove;
	int const SIZE = 128;
public:
	CNormalBoss(double, int, std::shared_ptr<CBaseBossBehavior>,std::shared_ptr<CBaseBossGraphic>);
	void upDate() override;
	void render() override;
	void init() override;
	void finalize() override;
	void hitObject(CBasePlayerBullet*) override;
	~CNormalBoss();
};

