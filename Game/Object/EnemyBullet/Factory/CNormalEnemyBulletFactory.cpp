#include "CNormalEnemyBulletFactory.h"



CNormalEnemyBulletFactory::CNormalEnemyBulletFactory()
{
}

std::shared_ptr<CBaseEnemyBullet> CNormalEnemyBulletFactory::create(double x, double y, std::shared_ptr<CBaseMove> pMove, int damage) {
	return std::make_shared<CNormalEnemyBullet>(x, y, pMove, damage);
}

CNormalEnemyBulletFactory::~CNormalEnemyBulletFactory()
{
}
