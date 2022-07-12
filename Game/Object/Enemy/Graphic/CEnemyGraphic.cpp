#include "CEnemyGraphic.h"


// Base ===============
CBaseEnemyGraphic::CBaseEnemyGraphic(){}
CBaseEnemyGraphic::~CBaseEnemyGraphic(){}

// CCircle ============
CCircleEnemyGraphic::CCircleEnemyGraphic(){}
CCircleEnemyGraphic::~CCircleEnemyGraphic() {}

void CCircleEnemyGraphic::render(CBaseObject* o) {
	DrawGraph(int(o->getX() - 32), int(o->getY() - 32), CImage::getInstance()->getCircleImage(), true);
}


// Gear ===============
CGearEnemyGraphic::CGearEnemyGraphic() { this->angle = 0; }
CGearEnemyGraphic::~CGearEnemyGraphic() {}

void CGearEnemyGraphic::render(CBaseObject* o) {
	this->angle += 0.05;
	DrawRotaGraph(int(o->getX()), int(o->getY()), 1.0, cos(this->angle) * 3,CImage::getInstance()->getGearImage(),true);
}

// Hexagon ===============
CHexagonEnemyGraphic::CHexagonEnemyGraphic() { this->angle = 0; }
CHexagonEnemyGraphic::~CHexagonEnemyGraphic() {}

void CHexagonEnemyGraphic::render(CBaseObject* o) {
	this->angle += 0.08;
	DrawRotaGraph(int(o->getX()), int(o->getY()), 1.0, this->angle, CImage::getInstance()->getHexagonImage(), true);
}

// Square ===============
CSquareEnemyGraphic::CSquareEnemyGraphic() { this->angle = 0; }
CSquareEnemyGraphic::~CSquareEnemyGraphic() {}

void CSquareEnemyGraphic::render(CBaseObject* o) {
	this->angle += 0.05;

	DrawRotaGraph(int(o->getX()), int(o->getY()), 1.0, cos(this->angle) * 3, CImage::getInstance()->getSquareImage(), true);
}
