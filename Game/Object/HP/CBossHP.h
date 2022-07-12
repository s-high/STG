#pragma once
#include "CBaseHP.h"
#include "DxLib.h"
#include "CImage.h"

class CBossHP :
	public CBaseHP
{
public:
	CBossHP(int);
	void render(double, double) override;
	~CBossHP();
};

