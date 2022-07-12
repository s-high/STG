#pragma once
#include "CStraightMove.h"

class CAppearanceMove
{
	bool isAppearing;
	int time;
	std::shared_ptr<CStraightMove> pMove;
public:
	CAppearanceMove(int,double,double);
	void move(CBaseObject*);
	bool getIsAppearing();
	~CAppearanceMove();
};

