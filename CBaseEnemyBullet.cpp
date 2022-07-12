#include "CBaseEnemyBullet.h"



CBaseEnemyBullet::CBaseEnemyBullet(double x, double y, std::shared_ptr<CBaseMove> pMove, int damage) : CBaseObject(x,y)
{
	this->damage = damage;
	this->pMove = pMove;
}

void CBaseEnemyBullet::dispatch(std::shared_ptr<CBaseObject> o) {
	o->hitObject(this);
}

CBaseEnemyBullet::~CBaseEnemyBullet()
{
}
