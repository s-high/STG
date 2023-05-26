#include "CPlayer.h"
#include "CBaseEnemy.h"
#include "CBaseEnemyBullet.h"
#include "CNormalEffect.h"
#include "CGameManager.h"

CPlayer::CPlayer(double x, double y) : CBaseObject(x, y) {
	this->hitShapeVector.push_back(std::make_shared<CCircle>(x, y, this->SIZE * this->COLLISION_CORRECTION));
	width = this->SIZE;
	height = this->SIZE;
	this->pMove = std::make_shared<CPlayerMove>(this->PLAYER_SPEED);
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
	int image = CImage::getInstance()->getPlayerImage(1);
	bool left = CKeyFacade::getInstance()->getKey(eKey::eLeft);
	bool right = CKeyFacade::getInstance()->getKey(eKey::eRight);

	if (left && !right)image = CImage::getInstance()->getPlayerImage(0);
	if (!left && right)image = CImage::getInstance()->getPlayerImage(2);


	DrawGraph(int(x - width * 0.5), int(y - height * 0.5), image, true);
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
	CNormalEffect::addExplode(CGameManager::pEffectManager, x, y, this->DEAD_EFFECT_LIFE);
	this->isAlive = false;
}

CPlayer::~CPlayer() {
}
