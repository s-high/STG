#include "CBaseEffect.h"



CBaseEffect::CBaseEffect(double x, double y, int life) : CBaseObject(x,y)
{
	this->life = life;
	this->maxLife = life;
}

void CBaseEffect::checkLife() {
	this->life -= 1;
	if (this->life <= 0) {
		this->isAlive = false;
	}
}

void CBaseEffect::init() {
	// pass
}

void CBaseEffect::dispatch(std::shared_ptr<CBaseObject> o) {
	// pass
}

CBaseEffect::~CBaseEffect()
{
}
