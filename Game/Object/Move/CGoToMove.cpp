#include "CGoToMove.h"



CGoToMove::CGoToMove(CBaseObject* o, double x,double y,double speed)
{
	double distance = sqrt((o->getX() - x) * (o->getX() - x) + (o->getY() - y) * (o->getY() - y));
	this->time = int(distance / speed);

	double angle = atan2(o->getY() - y, o->getX() - x);
	this->vx = cos(angle) * speed;
	this->vy = sin(angle) * speed;

	this->currentState = eState::Moving;

}

CGoToMove::CGoToMove(CBaseObject* o, double x, double y, int time) {
	this->time = time;

	double distance = sqrt((o->getX() - x) * (o->getX() - x) + (o->getY() - y) * (o->getY() - y));
	double speed = distance / double(time);

	double angle = atan2(y - o->getY(), x - o->getX());
	this->vx = cos(angle) * speed;
	this->vy = sin(angle) * speed;

	this->currentState = eState::Moving;
}


void CGoToMove::move(CBaseObject *o) {
	o->setX(o->getX() + this->vx);
	o->setY(o->getY() + this->vy);

	this->time--;
	if (time <= 0)this->currentState = eState::End;
}

CGoToMove::eState CGoToMove::getState() { return this->currentState; }

CGoToMove::~CGoToMove()
{
}
