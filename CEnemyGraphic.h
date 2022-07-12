#pragma once
#include "CBaseObject.h"
#include "CImage.h"

class CBaseEnemyGraphic
{
public:
	CBaseEnemyGraphic();
	virtual void render(CBaseObject*) = 0;
	~CBaseEnemyGraphic();
};

class CCircleEnemyGraphic :
	public CBaseEnemyGraphic
{
public:
	CCircleEnemyGraphic();
	void render(CBaseObject*);
	~CCircleEnemyGraphic();
};

class CGearEnemyGraphic : public CBaseEnemyGraphic
{
	double angle;
public:
	CGearEnemyGraphic();
	void render(CBaseObject*);
	~CGearEnemyGraphic();
};

class CHexagonEnemyGraphic : public CBaseEnemyGraphic
{
	double angle;
public:
	CHexagonEnemyGraphic();
	void render(CBaseObject*);
	~CHexagonEnemyGraphic();
};

class CSquareEnemyGraphic : public CBaseEnemyGraphic
{
	double angle;
public:
	CSquareEnemyGraphic();
	void render(CBaseObject*);
	~CSquareEnemyGraphic();
};