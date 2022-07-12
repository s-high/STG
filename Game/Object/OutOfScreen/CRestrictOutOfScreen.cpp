#include "CRestrictOutOfScreen.h"



CRestrictOutOfScreen::CRestrictOutOfScreen()
{
}

void CRestrictOutOfScreen::checkHitWall(CBaseObject* o) {
	if (o->getX() - o->getWidth() * 0.5 < 0)o->setX(o->getWidth() * 0.5);
	if (SCREEN_WIDTH < o->getX() + o->getWidth() * 0.5)o->setX(SCREEN_WIDTH - o->getWidth() * 0.5);
	if (o->getY() - o->getHeight() * 0.5 < 0)o->setY(o->getHeight() * 0.5);
	if (SCREEN_HEIGHT < o->getY() + o->getHeight() * 0.5)o->setY(SCREEN_HEIGHT - o->getHeight() * 0.5);
}

CRestrictOutOfScreen::~CRestrictOutOfScreen()
{
}
