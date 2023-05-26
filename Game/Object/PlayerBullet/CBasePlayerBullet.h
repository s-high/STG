#pragma once
#include "CBaseObject.h"
#include "CBaseMove.h"
#include "CCircle.h"
#include "CImage.h"
#include "CNormalEffect.h"

class CBasePlayerBullet : public CBaseObject {
	int const DEAD_EFFECT_LIFE = 30;
protected:
	std::shared_ptr<CBaseMove> pMove;
	int damage;
public:
	CBasePlayerBullet(double, double, std::shared_ptr<CBaseMove>, int);
	int getDamage();

	void dispatch(std::shared_ptr<CBaseObject>);
	void hitObject(CBaseEnemy*) override;
	void hitObject(CBaseBoss*) override;
	~CBasePlayerBullet();
};

