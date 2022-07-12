#include "CRandomFlyMove.h"



CRandomFlyMove::CRandomFlyMove(int moveTime, int intervalTime, std::shared_ptr<CRect>  pRect)
{
	this->MOVE_TIME = moveTime;
	this->moveTime = 0;
	this->INTERVAL_TIME = intervalTime;
	this->intervalTime = 0;
	this->pRect = pRect;
	this->currentPhase = ePhase::Moving;
}

CRandomFlyMove::CRandomFlyMove(int moveTime, int intervalTime)
{
	this->MOVE_TIME = moveTime;
	this->moveTime = 0;
	this->INTERVAL_TIME = intervalTime;
	this->intervalTime = 0;
	this->pRect = std::make_shared<CRect>(SCREEN_WIDTH * 0.5, 160, SCREEN_WIDTH - 100, 220);
}

void CRandomFlyMove::move(CBaseObject* o) {
	if (this->moveTime == 0 && this->intervalTime == 0) {
		this->moveInit(o->getX(), o->getY());
		this->moveTime += 1;
		this->currentPhase = ePhase::Moving;
	}

	if (0 < this->moveTime) {
		o->setX(o->getX() + this->vx);
		o->setY(o->getY() + this->vy);
		this->moveTime += 1;

		if (this->MOVE_TIME <= this->moveTime) {
			this->intervalTime += 1;
			this->moveTime = 0;
			this->currentPhase = ePhase::Waiting;
			return;
		}
	}

	if (0 < this->intervalTime) {
		this->intervalTime += 1;
		if (this->INTERVAL_TIME <= this->intervalTime) {
			this->intervalTime = 0;
			this->moveTime = 0;
		}
		return;
	}
	
}

CRandomFlyMove::ePhase CRandomFlyMove::getPhase() { return this->currentPhase; }

void CRandomFlyMove::setIntervalTime(int t) {
	this->INTERVAL_TIME = t;
}

void CRandomFlyMove::setMoveTime(int t) {
	this->MOVE_TIME = t;
}


void CRandomFlyMove::moveInit(double x, double y) {
	double nextX = GetRand(int(pRect->getWidth())) + pRect->getLeft();
	double nextY = GetRand(int(pRect->getHeight())) + pRect->getTop();

	double angle = atan2(nextY - y, nextX - x);
	double dist = sqrt((x - nextX) * (x - nextX) + (y - nextY) * (y - nextY));
	double speed = dist / this->MOVE_TIME;

	this->vx = speed * cos(angle);
	this->vy = speed * sin(angle);
}

CRandomFlyMove::~CRandomFlyMove()
{
}
