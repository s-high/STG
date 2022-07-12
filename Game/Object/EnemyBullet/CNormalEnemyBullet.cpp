#include "CNormalEnemyBullet.h"



CNormalEnemyBullet::CNormalEnemyBullet(double x, double y, std::shared_ptr<CBaseMove> pMove, int damage) : CBaseEnemyBullet(x,y,pMove,damage)
{
	
	width = 8;
	height = 8;
	this->hitShapeVector.push_back(std::make_shared<CCircle>(x, y, 8));
	this->pOutOfScreen = std::make_shared<CDeleteOutOfScreen>();
}

void CNormalEnemyBullet::upDate() {
	pMove->move(this);

	// end
	hitShapeVector.at(0)->setPos(x, y);
	pOutOfScreen->checkHitWall(this);
}

void CNormalEnemyBullet::render() {
	DrawGraph(int(x - width * 0.5), int(y - height * 0.5), CImage::getInstance()->getEnemyNormalBulletImage(),true);
}

void CNormalEnemyBullet::init() {

}

CNormalEnemyBullet::~CNormalEnemyBullet()
{
}
