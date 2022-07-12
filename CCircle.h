#pragma once
#include "CBaseShape.h"
#include "CRect.h"

class CCircle :
	public CBaseShape
{
	double diameter;
public:
	CCircle(double, double, double);
	void setDiameter(double);
	double getDiameter();
	bool dispatch(std::shared_ptr<CBaseShape>);
protected:
	bool isHit(CCircle*);
	bool isHit(CRect*);
public:
	~CCircle();
};

