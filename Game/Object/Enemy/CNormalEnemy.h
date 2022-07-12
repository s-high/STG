#pragma once
#include "CBaseEnemy.h"
#include "CEnemyGraphic.h"
#include "CCircleEnemyWeapon.h"

class CBasePlayerBullet;


class CNormalEnemy :
	public CBaseEnemy
{
	std::shared_ptr<CBaseEnemyGraphic> pGraphic;
	std::shared_ptr<CBaseEnemyWeapon> pWeapon;
	std::shared_ptr<CBaseMove> pMove;
public:
	CNormalEnemy(double, double, int, std::shared_ptr<CBaseEnemyGraphic>, std::shared_ptr<CBaseEnemyWeapon>, std::shared_ptr<CBaseMove>);
	void upDate() override;
	void render() override;
	void init() override;
	void finalize() override;

	void dispatch(std::shared_ptr<CBaseObject>);
	void hitObject(CBasePlayerBullet*);
	~CNormalEnemy();
};

