#include "CCircleEnemyShot.h"


CCircleEnemyShot::CCircleEnemyShot(std::shared_ptr<CBaseEnemyBulletFactory> pEBFtr, double speed, int n, double initAngle = 0) : CBaseEnemyShot(pEBFtr)
{
	this->speed = speed;
	this->n = n;
	this->initAngle = initAngle;
}

void CCircleEnemyShot::shot(CBaseObject* o) {
	this->shot(o->getX(), o->getY());
}

void CCircleEnemyShot::shot(double x, double y) {
	double angle = M_PI * 2 / this->n;
	for (int i = 0;i < this->n;i++) {
		CGameManager::pEnemyBulletManager->addObject(
			this->pEBFtr->create(x,y,
				std::make_shared<CStraightMove>(cos(this->initAngle + angle * i) * speed, sin(this->initAngle + angle * i) * speed),10
			)
		);
	}
}

void CCircleEnemyShot::setInitAngle(double initAngle) {
	this->initAngle = initAngle;
}

double CCircleEnemyShot::getInitAngle() { return this->initAngle; }

CCircleEnemyShot::~CCircleEnemyShot()
{
}
