#include "CDisplayBoss.h"



CDisplayBoss::CDisplayBoss(double x, double y, std::shared_ptr<CBaseBossGraphic> pGraphic) : CBaseBoss(x, y, 100)
{
	this->pGraphic = pGraphic;
}

void CDisplayBoss::upDate(){}
void CDisplayBoss::render() {
	this->pHP->render(this->x, this->y);
	this->pGraphic->render(this);
}
void CDisplayBoss::init() {}
void CDisplayBoss::finalize() {}

CDisplayBoss::~CDisplayBoss()
{
}
