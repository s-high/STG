#include "CNormalPlayerBulletFactory.h"



CNormalPlayerBulletFactory::CNormalPlayerBulletFactory()
{
}

std::shared_ptr<CBasePlayerBullet> CNormalPlayerBulletFactory::create(double x, double y, std::shared_ptr<CBaseMove> pMove, int damage) {
	return std::make_shared<CNormalPlayerBullet>(x, y, pMove, damage);
}

CNormalPlayerBulletFactory::~CNormalPlayerBulletFactory()
{
}
