#pragma once
#include "CBaseEffect.h"
#include "CStraightMove.h"
#include "CImage.h"
#include "CRandom.h"

class CObjectManager;

class CNormalEffect :
	public CBaseEffect
{
	std::shared_ptr<CStraightMove> pMove;
public:
	static double getSpeed();
	CNormalEffect(double,double,int,double,double);
	void upDate();
	void render();
	static std::shared_ptr<CNormalEffect> create(double, double, int, double, double);
	static std::shared_ptr<CNormalEffect> create(double, double, int);
	static std::vector<std::shared_ptr<CNormalEffect>> createExplode(double, double, int, int);

	static void add(std::shared_ptr<CObjectManager>, double, double, int, double, double);
	static void add(std::shared_ptr<CObjectManager>, double, double, int);
	static void addExplode(std::shared_ptr<CObjectManager>, double, double, int);

	~CNormalEffect();
};

