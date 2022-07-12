#include "CPlayerMove.h"



CPlayerMove::CPlayerMove(double speed)
{
	this->speed = speed;
}

void CPlayerMove::move(CBaseObject* o) {
	if (CKeyFacade::getInstance()->getKey(eKey::eLeft))o->setX(o->getX() - speed);
	if (CKeyFacade::getInstance()->getKey(eKey::eRight))o->setX(o->getX() + speed);
	if (CKeyFacade::getInstance()->getKey(eKey::eUp))o->setY(o->getY() - speed);
	if (CKeyFacade::getInstance()->getKey(eKey::eDown))o->setY(o->getY() + speed);
}

CPlayerMove::~CPlayerMove()
{
}
