#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <memory>
#include "CBaseShape.h"
#include "CImage.h"
#include "CRandom.h"
#include "DxLib.h"

class CPlayer;
class CBasePlayerBullet;
class CBaseEnemy;
class CBaseEnemyBullet;
class CBaseBoss;

class CBaseObject
{
protected:
	double x, y;
	bool isAlive;
	double width, height;
	std::vector<std::shared_ptr<CBaseShape>> hitShapeVector;
public:
	CBaseObject(double,double);
	void setX(double);
	void setY(double);
	double getX();
	double getY();
	void setIsAlive(bool);
	bool getIsAlive();
	double getWidth();
	double getHeight();
	std::vector<std::shared_ptr<CBaseShape>> getHitShape();
	virtual void upDate() = 0;
	virtual void render() = 0;
	virtual void init();
	virtual void finalize();

	virtual void dispatch(std::shared_ptr<CBaseObject>) = 0;
	virtual void hitObject(CPlayer*);
	virtual void hitObject(CBaseEnemy*);
	virtual void hitObject(CBasePlayerBullet*);
	virtual void hitObject(CBaseEnemyBullet*);
	virtual void hitObject(CBaseBoss*);
	~CBaseObject();
};

