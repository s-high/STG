#include "CBasePlayerBullet.h"
#include "CGameManager.h"


CBasePlayerBullet::CBasePlayerBullet(double x, double y, std::shared_ptr<CBaseMove> pMove, int damage) : CBaseObject(x,y)
{
	this->pMove = pMove;
	this->damage = damage;
}

int CBasePlayerBullet::getDamage() { return this->damage; }

void CBasePlayerBullet::dispatch(std::shared_ptr<CBaseObject> o) {
	o->hitObject(this);
}

void CBasePlayerBullet::hitObject(CBaseEnemy* e) {
	this->isAlive = false;
	CGameManager::pEffectManager->addObject(CNormalEffect::create(x,y,30));
}

void CBasePlayerBullet::hitObject(CBaseBoss* o) {
	this->isAlive = false;
	CNormalEffect::add(CGameManager::pEffectManager, this->x, this->y, 30);
}


CBasePlayerBullet::~CBasePlayerBullet()
{
}
