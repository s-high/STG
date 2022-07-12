#include "CCircle.h"



CCircle::CCircle(double x, double y, double diameter) : CBaseShape(x,y)
{
	this->diameter = diameter;
}

void CCircle::setDiameter(double d) {
	this->diameter = d;
}

double CCircle::getDiameter() { return this->diameter; }

bool CCircle::isHit(CCircle *c) {
	return (c->getX() - this->getX()) * (c->getX() - this->getX()) + (c->getY() - this->getY()) * (c->getY() - this->getY())
		< ((c->getDiameter() + this->getDiameter()) * 0.5) * ((c->getDiameter() + this->getDiameter()) * 0.5);
}

bool CCircle::isHit(CRect *r) {
	return (this->getX() - r->getX()) * (this->getX() - r->getX()) + (this->getY() - r->getY()) * (this->getY() - r->getY())
		< ((this->getDiameter() + r->getWidth() * 0.5) * 0.5) * ((this->getDiameter() + r->getHeight() * 0.5) * 0.5);
}

bool CCircle::dispatch(std::shared_ptr<CBaseShape> s) {
	return s->isHit(this);
}

CCircle::~CCircle()
{
}
