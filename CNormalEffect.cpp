#include "CNormalEffect.h"
#include "CObjectManager.h"


CNormalEffect::CNormalEffect(double x, double y, int life, double vx, double vy) : CBaseEffect(x,y,life)
{
	this->pMove = std::make_shared<CStraightMove>(vx, vy);
}

void CNormalEffect::upDate() {
	this->checkLife();
	this->pMove->move(this);
}

void CNormalEffect::render() {
	double percent = double(this->life) / double(this->maxLife);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, int(255 * (1 - percent)));
	DrawExtendGraph(x - (64 * percent) * 0.5, y - (64 * percent) * 0.5, x + (64 * percent) * 0.5, y + (64 * percent) * 0.5, CImage::getInstance()->getNormalEffect(), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

double CNormalEffect::getSpeed() {
	return double(1 + CRandom::getInstance()->getRandom() - 0.5);
}

std::shared_ptr<CNormalEffect> CNormalEffect::create(double x, double y, int life, double vx, double vy) {
	return std::make_shared<CNormalEffect>(x, y, life, vx, vy);
}

std::shared_ptr<CNormalEffect> CNormalEffect::create(double x, double y, int life) {
	double angle = CRandom::getInstance()->getRandomAngle();
	double speed = CNormalEffect::getSpeed();
	
	return CNormalEffect::create(x, y, life, cos(angle) * speed, sin(angle) * speed);
}

std::vector<std::shared_ptr<CNormalEffect>> CNormalEffect::createExplode(double x, double y, int life, int n) {
	std::vector<std::shared_ptr<CNormalEffect>> ans;
	for (int i = 0;i < n;i++) {
		ans.push_back(CNormalEffect::create(x, y, life));
	}
	return ans;
}

void CNormalEffect::add(std::shared_ptr<CObjectManager> pObjMgr, double x, double y, int life, double vx, double vy) {
	pObjMgr->addObject(CNormalEffect::create(x, y, life, vx, vy));
}

void CNormalEffect::add(std::shared_ptr<CObjectManager> pObjMgr, double x, double y, int life) {
	pObjMgr->addObject(CNormalEffect::create(x, y, life));
}

void CNormalEffect::addExplode(std::shared_ptr<CObjectManager> pObjMgr, double x, double y, int n) {
	for (int i = 0;i < n;i++) {
		int life = 30 + CRandom::getInstance()->getRandom(30);
		pObjMgr->addObject(CNormalEffect::create(x, y, life));
	}
}

CNormalEffect::~CNormalEffect()
{
}
