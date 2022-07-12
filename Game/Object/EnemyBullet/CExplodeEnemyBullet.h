#pragma once
#include "CBasePlayerBullet.h"
#include "CBaseEnemyShot.h"

class CExplodeEnemyBullet :
	public CBaseEnemyBullet
{
	int life;
	std::shared_ptr<CBaseEnemyShot> pShot;
public:
	CExplodeEnemyBullet(double, double, std::shared_ptr<CBaseMove>, int, std::shared_ptr<CBaseEnemyShot>);
	void upDate() override;
	void render() override;
	void init() override;
	~CExplodeEnemyBullet();
};

