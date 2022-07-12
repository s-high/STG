#pragma once
#include "CBaseHP.h"
#include "CImage.h"

class CNormalHP :
	public CBaseHP
{
public:
	CNormalHP(int);
	void render(double,double) override;
	~CNormalHP();
};

