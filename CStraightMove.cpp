#include "CStraightMove.h"



CStraightMove::CStraightMove(double vx,double vy)
{
	this->vx = vx;
	this->vy = vy;
}

void CStraightMove::move(CBaseObject* o) {
	o->setX(o->getX() + this->vx);
	o->setY(o->getY() + this->vy);
}

CStraightMove::~CStraightMove()
{
}
