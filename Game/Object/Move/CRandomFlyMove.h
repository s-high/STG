#pragma once
#include "CBaseMove.h"
#include "CRect.h"
#include "CRandom.h"
#include "extern.h"
#include "DxLib.h"

class CRandomFlyMove :
	public CBaseMove
{
public:
	enum ePhase {
		Moving = 0,
		Waiting = 1
	};
private:
	int MOVE_TIME;
	int moveTime;
	int INTERVAL_TIME;
	int intervalTime;
	std::shared_ptr<CRect> pRect;

	double vx, vy;
	ePhase currentPhase;

	void moveInit(double,double);
public:
	CRandomFlyMove(int,int, std::shared_ptr<CRect>);
	CRandomFlyMove(int, int);
	void move(CBaseObject*);
	ePhase getPhase();
	void setIntervalTime(int);
	void setMoveTime(int);
	~CRandomFlyMove();
};

