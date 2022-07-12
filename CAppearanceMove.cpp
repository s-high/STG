#include "CAppearanceMove.h"



CAppearanceMove::CAppearanceMove(int time, double vx, double vy)
{
	this->pMove = std::make_shared<CStraightMove>(vx, vy);
	this->time = time;
	this->isAppearing = true;
}

void CAppearanceMove::move(CBaseObject* o) {
	this->time -= 1;
	this->pMove->move(o);
	if (this->time <= 0)isAppearing = false;
}

bool CAppearanceMove::getIsAppearing() {
	return this->isAppearing;
}

CAppearanceMove::~CAppearanceMove()
{
}
