#include "CNormalPlayerBullet.h"
#include "CGameManager.h"


CNormalPlayerBullet::CNormalPlayerBullet(double x, double y, std::shared_ptr<CBaseMove> pMove, int damage) : CBasePlayerBullet(x,y,pMove,damage)
{
	this->width = this->SIZE;
	this->height = this->SIZE;
	this->hitShapeVector.push_back(std::make_shared<CCircle>(x,y, this->SIZE));
	this->pOutScreen = std::make_shared<CDeleteOutOfScreen>();
}

void CNormalPlayerBullet::upDate(){
	this->pMove->move(this);
	this->pOutScreen->checkHitWall(this);
	this->hitShapeVector.at(0)->setPos(x, y);
}

void CNormalPlayerBullet::render(){
	DrawGraph(int(x - width * 0.5), int(y - height * 0.5),CImage::getInstance()->getPlayerNormalBulletImage(),true);
}

void CNormalPlayerBullet::init() {
	//pass
}

CNormalPlayerBullet::~CNormalPlayerBullet()
{
}
