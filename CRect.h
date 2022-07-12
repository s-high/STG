#pragma once
#include "CBaseShape.h"
#include "CCircle.h"

class CRect :
	public CBaseShape
{
	double width, height;
public:
	/*
	@param x
	@param y
	@param width
	@param height
	*/
	CRect(double,double,double,double);
	void setWidth(double);
	void setHeight(double);
	double getWidth();
	double getHeight();

	double getLeft();
	double getRight();
	double getTop();
	double getBottom();

	bool dispatch(std::shared_ptr<CBaseShape>);
protected:
	bool isHit(CCircle*);
	bool isHit(CRect*);
public:

	~CRect();
};

