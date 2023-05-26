#include "CCollision.h"



CCollision::CCollision(std::shared_ptr<CPlayer> pPlayer, std::shared_ptr<CObjectManager> pPBMgr
					   , std::shared_ptr<CObjectManager> pEMgr, std::shared_ptr<CObjectManager> pEBMgr, std::shared_ptr<CObjectManager> pBMgr) {
	// player,pBullet,enemy,eBullet,Boss
	this->pPlayer = pPlayer;
	this->pPBMgr = pPBMgr;
	this->pEMgr = pEMgr;
	this->pEBMgr = pEBMgr;
	this->pBMgr = pBMgr;
}

bool CCollision::isHitObjectAndObject(std::shared_ptr<CBaseObject> o1, std::shared_ptr<CBaseObject> o2) {
	for (auto s1 : o1->getHitShape())for (auto s2 : o2->getHitShape()) {
		if (s1->dispatch(s2)) {
			return true;
		}
	}
	return false;
}

void CCollision::checkObjectAndObject(std::vector<std::shared_ptr<CBaseObject>> ov1, std::vector<std::shared_ptr<CBaseObject>> ov2) {
	for (auto o1 : ov1) {
		checkObjectAndObject(o1, ov2);
	}
}

void CCollision::checkObjectAndObject(std::shared_ptr<CBaseObject> o1, std::vector<std::shared_ptr<CBaseObject>> ov) {
	for (auto o2 : ov) {
		if (isHitObjectAndObject(o1, o2)) {
			o1->dispatch(o2);
			o2->dispatch(o1);
		}
	}
}

void CCollision::upDate() {
	checkObjectAndObject(this->pPlayer, this->pEBMgr->getObject());
	checkObjectAndObject(this->pPlayer, this->pEMgr->getObject());
	checkObjectAndObject(this->pPlayer, this->pBMgr->getObject());

	checkObjectAndObject(this->pEMgr->getObject(), this->pPBMgr->getObject());
	checkObjectAndObject(this->pBMgr->getObject(), this->pPBMgr->getObject());
}

CCollision::~CCollision() {
}
