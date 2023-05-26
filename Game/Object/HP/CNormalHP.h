#pragma once
#include "CBaseHP.h"
#include "CImage.h"

class CNormalHP :
	public CBaseHP
{
	int const SIZE = 64;
public:
	CNormalHP(int);
	void render(double,double) override;
	~CNormalHP();
};

