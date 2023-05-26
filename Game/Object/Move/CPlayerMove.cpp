#include "CPlayerMove.h"



CPlayerMove::CPlayerMove(double speed)
{
	this->speed = speed;
}

void CPlayerMove::move(CBaseObject* o) {
	double currentSpeed = this->speed;

	if (CKeyFacade::getInstance()->getKey(eKey::eSpace))currentSpeed *= 0.5;

	if (CKeyFacade::getInstance()->getKey(eKey::eLeft))o->setX(o->getX() - currentSpeed);
	if (CKeyFacade::getInstance()->getKey(eKey::eRight))o->setX(o->getX() + currentSpeed);
	if (CKeyFacade::getInstance()->getKey(eKey::eUp))o->setY(o->getY() - currentSpeed);
	if (CKeyFacade::getInstance()->getKey(eKey::eDown))o->setY(o->getY() + currentSpeed);
}

CPlayerMove::~CPlayerMove()
{
}
