#pragma once
#include <memory>

class CCircle;
class CRect;

class CBaseShape
{
protected:
	double x, y;
public:
	CBaseShape(double, double);
	void setX(double);
	void setY(double);
	void setPos(double, double);
	double getX();
	double getY();
	virtual bool dispatch(std::shared_ptr<CBaseShape>) = 0;
	virtual bool isHit(CCircle*) = 0;
	virtual bool isHit(CRect*) = 0;
public:
	~CBaseShape();
};

