#pragma once
#include "CSingleton.h"
#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <cmath>

class CRandom :
	public CSingleton<CRandom>
{
	friend CSingleton<CRandom>;
	CRandom();
public:
	int getRandom(int);
	int getRandom(int, int);

	//return [0,1)
	double getRandom();

	//return [0,2pi)
	double getRandomAngle();
	~CRandom();
};

