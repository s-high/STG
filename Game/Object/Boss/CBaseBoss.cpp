#include "CBaseBoss.h"
#include "CBasePlayerBullet.h"


CBaseBoss::CBaseBoss(double x, double y, int hp) : CBaseObject(x,y)
{
	this->pHP = std::make_shared<CBossHP>(hp);
}

void CBaseBoss::dispatch(std::shared_ptr<CBaseObject> o) {
	o->hitObject(this);
}

void CBaseBoss::hitObject(CBasePlayerBullet* pb) {
	// damage
	// (default process)
	this->pHP->addDamage(pb->getDamage());
	if (this->pHP->getHP() <= 0)this->isAlive = false;
}
std::shared_ptr<CBossHP> CBaseBoss::getHP() {
	return this->pHP;
}

CBaseBoss::~CBaseBoss()
{
}
