#pragma once
#include "CBaseEnemyBullet.h"
#include "CDeleteOutOfScreen.h"

class CNormalEnemyBullet :
	public CBaseEnemyBullet
{
	std::shared_ptr<CBaseOutOfScreen> pOutOfScreen;
public:
	CNormalEnemyBullet(double, double, std::shared_ptr<CBaseMove>, int);
	void upDate();
	void render();
	void init();
	~CNormalEnemyBullet();
};

