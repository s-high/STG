#include "CExplodeEnemyBullet.h"



CExplodeEnemyBullet::CExplodeEnemyBullet(double x, double y, std::shared_ptr<CBaseMove> pMove, int life, std::shared_ptr<CBaseEnemyShot> pShot) : CBaseEnemyBullet(x,y,pMove,10)
{
	this->life = life;
	this->pShot = pShot;
	width = 32;
	height = 32;
	this->hitShapeVector.push_back(std::make_shared<CCircle>(x, y, 16));
}

void CExplodeEnemyBullet::upDate() {
	this->life -= 1;
	this->pMove->move(this);
	if (this->life <= 0) {
		this->isAlive = false;
		this->pShot->shot(this);
	}
}

void CExplodeEnemyBullet::render() {
	DrawGraph(int(x - width * 0.5), int(y - height * 0.5), CImage::getInstance()->getEnemyExplodeBulletImage(), true);
}

void CExplodeEnemyBullet::init() {

}

CExplodeEnemyBullet::~CExplodeEnemyBullet()
{
}
