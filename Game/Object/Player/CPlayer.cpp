#include "CPlayer.h"
#include "CBaseEnemy.h"
#include "CBaseEnemyBullet.h"
#include "CNormalEffect.h"
#include "CGameManager.h"

CPlayer::CPlayer(double x,double y) : CBaseObject(x,y)
{
	this->hitShapeVector.push_back(std::make_shared<CCircle>(x, y, 16));
	width = 32;
	height = 32;
	this->pMove = std::make_shared<CPlayerMove>(5);
	this->pOutOfScreen = std::make_shared<CRestrictOutOfScreen>();
}

void CPlayer::upDate() {
	pMove->move(this);
	pOutOfScreen->checkHitWall(this);
	pWeapon->attack(this);

	// end process...
	this->hitShapeVector.at(0)->setX(this->x);
	this->hitShapeVector.at(0)->setY(this->y);
}

void CPlayer::render() {
	DrawGraph(x - width * 0.5, y - height * 0.5,CImage::getInstance()->getPlayerImage(1),true);
}

void CPlayer::init() {
	
}

void CPlayer::setMove(std::shared_ptr<CBaseMove> pMove) {
	this->pMove = pMove;
}

void CPlayer::setWeapon(std::shared_ptr<CBasePlayerWeapon> pWeapon) {
	this->pWeapon = pWeapon;
}

void CPlayer::createPlayer(std::shared_ptr<CBaseMove> pMove, std::shared_ptr<CBasePlayerWeapon> pWeapon) {
	this->setMove(pMove);
	this->setWeapon(pWeapon);
}

void CPlayer::dispatch(std::shared_ptr<CBaseObject> o) {
	o->hitObject(this);
}

void CPlayer::hitObject(CBaseEnemy* e) {
	deadProcess();
}

void CPlayer::hitObject(CBaseBoss* b) {
	deadProcess();
}

void CPlayer::hitObject(CBaseEnemyBullet* eb) {
	deadProcess();
}

void CPlayer::deadProcess() {
	CNormalEffect::addExplode(CGameManager::pEffectManager, x, y, 10);
	this->isAlive = false;
}

CPlayer::~CPlayer()
{
}
