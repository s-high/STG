#include "CRect.h"


CRect::CRect(double x, double y, double w, double h) : CBaseShape(x,y)
{
	this->width = w;
	this->height = h;
}

void CRect::setWidth(double w) {
	this->width = w;
}

void CRect::setHeight(double h) {
	this->height = h;
}

double CRect::getWidth() { return width; }
double CRect::getHeight() { return height; }

double CRect::getLeft() { return x - width * 0.5; }
double CRect::getRight() { return x + width * 0.5; }
double CRect::getTop() { return y - height * 0.5; }
double CRect::getBottom() { return y + height * 0.5; }

bool CRect::dispatch(std::shared_ptr<CBaseShape> s) {
	return s->isHit(this);
}

bool CRect::isHit(CCircle *c) {
	return (c->getX() - this->getX()) * (c->getX() - this->getX()) + (c->getY() - this->getY()) * (c->getY() - this->getY())
		< ((c->getDiameter() + this->getWidth() * 0.5) * 0.5) * ((c->getDiameter() + this->getHeight() * 0.5) * 0.5);
}

bool CRect::isHit(CRect *r) {
	return true;
}

CRect::~CRect()
{
}
