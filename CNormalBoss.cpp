#include "CNormalBoss.h"
#include "CBasePlayerBullet.h"
#include "CGameManager.h"

CNormalBoss::CNormalBoss(double x, int hp, std::shared_ptr<CBaseBossBehavior> pBehavior, std::shared_ptr<CBaseBossGraphic> pGraphic) : CBaseBoss(x,-200,hp)
{
	this->width = 128;
	this->height = 128;
	this->pGraphic = pGraphic;
	this->pBehavior = pBehavior;
	this->pAMove = std::make_shared<CAppearanceMove>(150,0,2);
	this->hitShapeVector.push_back(std::make_shared<CCircle>(x, y, 128));
}

void CNormalBoss::upDate(){
	if (this->pAMove->getIsAppearing()) this->pAMove->move(this);
	else this->pBehavior->upDate(this);
	
	this->hitShapeVector.at(0)->setPos(x, y);
}

void CNormalBoss::render() {
	this->pHP->render(this->x, this->y);
	this->pGraphic->render(this);
}

void CNormalBoss::init() {

}

void CNormalBoss::finalize() {
	CNormalEffect::addExplode(CGameManager::pEffectManager,this->x,this->y,20);
}

void CNormalBoss::hitObject(CBasePlayerBullet* pb) {
	if (!this->pAMove->getIsAppearing()) {
		this->pHP->addDamage(pb->getDamage());
		if (pHP->getHP() <= 0)this->isAlive = false;
	}
}

CNormalBoss::~CNormalBoss()
{
	
}
