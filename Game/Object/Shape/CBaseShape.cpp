#include "CBaseShape.h"
#include "CRect.h"
#include "CCircle.h"


CBaseShape::CBaseShape(double x, double y)
{
	this->x = x;
	this->y = y;
}

void CBaseShape::setX(double x) {
	this->x = x;
}
void CBaseShape::setY(double y) {
	this->y = y;
}
void CBaseShape::setPos(double x, double y) {
	this->setX(x);
	this->setY(y);
}

double CBaseShape::getX() { return this->x; }
double CBaseShape::getY() { return this->y; }

CBaseShape::~CBaseShape()
{
}
