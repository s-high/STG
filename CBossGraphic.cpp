#include "CBossGraphic.h"


// Base ======================
CBaseBossGraphic::CBaseBossGraphic(){}
CBaseBossGraphic::~CBaseBossGraphic(){}

// Circle =====================
CCircleBossGraphic::CCircleBossGraphic(){}
CCircleBossGraphic::~CCircleBossGraphic() {}

void CCircleBossGraphic::render(CBaseObject* o) {
	DrawGraph(o->getX() - 64, o->getY() - 64, CImage::getInstance()->getBossCircleImage(), true);
}

// Square =====================
CSquareBossGraphic::CSquareBossGraphic() { angle = 0; }
CSquareBossGraphic::~CSquareBossGraphic() {}

void CSquareBossGraphic::render(CBaseObject* o) {
	this->angle += 0.05;
	DrawRotaGraph(o->getX(), o->getY(), 1.0, cos(this->angle) * 3, CImage::getInstance()->getBossSquareImage(), true);
}

// Gear =====================
CGearBossGraphic::CGearBossGraphic() { angle = 0; }
CGearBossGraphic::~CGearBossGraphic() {}

void CGearBossGraphic::render(CBaseObject* o) {
	this->angle += 0.05;
	DrawRotaGraph(o->getX(), o->getY(), 1.0, cos(this->angle) * 3, CImage::getInstance()->getBossGearImage(), true);
}


// Hexagon =====================
CHexagonBossGraphic::CHexagonBossGraphic() { angle = 0; }
CHexagonBossGraphic::~CHexagonBossGraphic() {}

void CHexagonBossGraphic::render(CBaseObject* o) {
	this->angle += 3;
	DrawRotaGraph(o->getX(), o->getY(), 1.0, this->angle, CImage::getInstance()->getBossHexagonImage(), true);
}
