#pragma once
#include "CBaseObject.h"
#include "CImage.h"

class CBaseBossGraphic
{
public:
	int const SIZE = 128;
public:
	CBaseBossGraphic();
	virtual void render(CBaseObject*) = 0;
	~CBaseBossGraphic();
};

class CCircleBossGraphic : public CBaseBossGraphic
{
public:
	CCircleBossGraphic();
	void render(CBaseObject*);
	~CCircleBossGraphic();
};

class CSquareBossGraphic : public CBaseBossGraphic
{
	double angle;
public:
	CSquareBossGraphic();
	void render(CBaseObject*);
	~CSquareBossGraphic();
};

class CGearBossGraphic : public CBaseBossGraphic
{
	double angle;
public:
	CGearBossGraphic();
	void render(CBaseObject*);
	~CGearBossGraphic();
};


class CHexagonBossGraphic : public CBaseBossGraphic
{
	double angle;
public:
	CHexagonBossGraphic();
	void render(CBaseObject*);
	~CHexagonBossGraphic();
};
