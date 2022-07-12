#include "CBaseObject.h"
#include "CPlayer.h"
#include "CBasePlayerBullet.h"
#include "CBaseEnemy.h"
#include "CBaseEnemyBullet.h"


CBaseObject::CBaseObject(double x, double y)
{
	this->x = x;
	this->y = y;
	isAlive = true;
}

void CBaseObject::setX(double x) {
	this->x = x;
}

void CBaseObject::setY(double y) {
	this->y = y;
}

double CBaseObject::getX() { return x; }
double CBaseObject::getY() { return y; }

void CBaseObject::setIsAlive(bool flag) {
	isAlive = flag;
}

bool CBaseObject::getIsAlive() { return isAlive; }

double CBaseObject::getWidth() { return width; }
double CBaseObject::getHeight() { return height; }

void CBaseObject::hitObject(CPlayer*){}
void CBaseObject::hitObject(CBaseEnemy*){}
void CBaseObject::hitObject(CBasePlayerBullet*){}
void CBaseObject::hitObject(CBaseEnemyBullet*){}
void CBaseObject::hitObject(CBaseBoss*){}

void CBaseObject::init(){}
void CBaseObject::finalize(){}

std::vector<std::shared_ptr<CBaseShape>> CBaseObject::getHitShape() {
	return this->hitShapeVector;
}

CBaseObject::~CBaseObject()
{
}
