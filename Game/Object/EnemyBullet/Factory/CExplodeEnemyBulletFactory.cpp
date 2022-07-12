#include "CExplodeEnemyBulletFactory.h"



CExplodeEnemyBulletFactory::CExplodeEnemyBulletFactory(int life, std::shared_ptr<CBaseEnemyShot> pShot)
{
	this->pShot = pShot;
	this->life = life;
}

std::shared_ptr<CBaseEnemyBullet> CExplodeEnemyBulletFactory::create(double x, double y, std::shared_ptr<CBaseMove> m, int d) {
	return std::make_shared<CExplodeEnemyBullet>(x, y, m, this->life, this->pShot);
}

CExplodeEnemyBulletFactory::~CExplodeEnemyBulletFactory()
{
}
