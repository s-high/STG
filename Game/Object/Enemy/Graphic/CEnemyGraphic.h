#pragma once
#include "CBaseObject.h"
#include "CImage.h"

class CBaseEnemyGraphic {
protected:
	int const SIZE = 64;
public:
	CBaseEnemyGraphic();
	virtual void render(CBaseObject*) = 0;
	~CBaseEnemyGraphic();
};

class CCircleEnemyGraphic :
	public CBaseEnemyGraphic {

public:
	CCircleEnemyGraphic();
	void render(CBaseObject*);
	~CCircleEnemyGraphic();
};

class CGearEnemyGraphic : public CBaseEnemyGraphic {
	double angle;
public:
	CGearEnemyGraphic();
	void render(CBaseObject*);
	~CGearEnemyGraphic();
};

class CHexagonEnemyGraphic : public CBaseEnemyGraphic {
	double angle;
	double const dAngle = 0.08;
public:
	CHexagonEnemyGraphic();
	void render(CBaseObject*);
	~CHexagonEnemyGraphic();
};

class CSquareEnemyGraphic : public CBaseEnemyGraphic {
	double angle;
	double const dAngle = 0.05;
public:
	CSquareEnemyGraphic();
	void render(CBaseObject*);
	~CSquareEnemyGraphic();
};