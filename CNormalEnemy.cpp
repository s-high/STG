#include "CNormalEnemy.h"
#include "CBasePlayerBullet.h"
#include "CGameManager.h"
#include "CNormalEffect.h"

CNormalEnemy::CNormalEnemy(double x, double y, int hp, std::shared_ptr<CBaseEnemyGraphic> pGraphic
	, std::shared_ptr<CBaseEnemyWeapon> pWeapon, std::shared_ptr<CBaseMove> pMove) : CBaseEnemy(x, y, hp)
{
	this->pGraphic = pGraphic;
	this->pWeapon = pWeapon;
	this->pMove = pMove;
	width = 64;
	height = 64;

	this->hitShapeVector.push_back(std::make_shared<CCircle>(x,y,64));
}

void CNormalEnemy::upDate() {
	pWeapon->attack(this);
	pMove->move(this);

	// end
	this->hitShapeVector.at(0)->setPos(x, y);
	if (this->pHP->getHP() <= 0)this->isAlive = false;
}

void CNormalEnemy::render() {
	this->pHP->render(this->x, this->y);
	this->pGraphic->render(this);
}

void CNormalEnemy::init() {

}

void CNormalEnemy::dispatch(std::shared_ptr<CBaseObject> o) {
	o->hitObject(this);
}

void CNormalEnemy::hitObject(CBasePlayerBullet* pb) {
	this->pHP->addDamage(pb->getDamage());
}

void CNormalEnemy::finalize() {
	CNormalEffect::addExplode(CGameManager::pEffectManager, x, y, 10);
}

CNormalEnemy::~CNormalEnemy()
{
		
}
