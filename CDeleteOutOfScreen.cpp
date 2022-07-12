#include "CDeleteOutOfScreen.h"



CDeleteOutOfScreen::CDeleteOutOfScreen()
{
	
}

void CDeleteOutOfScreen::checkHitWall(CBaseObject* o) {
	if (o->getX() + o->getWidth() * 0.5 < 0 or
		SCREEN_WIDTH < o->getX() - o->getWidth() * 0.5 or
		o->getY() + o->getHeight() * 0.5 < 0 or
		SCREEN_HEIGHT < o->getY() - o->getHeight() * 0.5) {
		o->setIsAlive(false);
	}
}

CDeleteOutOfScreen::~CDeleteOutOfScreen()
{
}
