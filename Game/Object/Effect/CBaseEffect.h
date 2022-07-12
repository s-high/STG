#pragma once
#include "CBaseObject.h"

class CBaseEffect : public CBaseObject
{
protected:
	int life;
	int maxLife;
public:
	CBaseEffect(double, double, int);
	void checkLife();
	void init() override;
	void dispatch(std::shared_ptr<CBaseObject>) override;
	~CBaseEffect();
};

