#include "CReflectMove.h"



CReflectMove::CReflectMove(double vx, double vy)
{
	this->vx = vx;
	this->vy = vy;
}

void CReflectMove::move(CBaseObject* o) {
	o->setX(o->getX() + this->vx);
	o->setY(o->getY() + this->vy);

	if (o->getX() - o->getWidth() * 0.5 <= 0 || SCREEN_WIDTH < o->getX() + o->getWidth() * 0.5)this->vx *= -1;
	if (o->getY() - o->getHeight() * 0.5 <= 0 || SCREEN_HEIGHT < o->getY() + o->getHeight() * 0.5)this->vy *= -1;
}

double CReflectMove::getVX() const { return this->vx; }
double CReflectMove::getVY() const { return this->vy; }

CReflectMove::~CReflectMove()
{
}
