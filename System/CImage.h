#pragma once
#include <DxLib.h>
#include <vector>
#include "CSingleton.h"

class CImage : public CSingleton<CImage>
{
	friend class CSingleton<CImage>;
	CImage();

	int myLoadGraph(const char*);
	int myLoadDivGraph(const char*, int, int, int, int, int, int*);
	std::vector<int> imageHandles;

	int titleImage;
	int playerImage[3];
	int playerNormalBullet;

	int enemyCircleImage, enemyHexagonImage, enemyGearImage, enemySquareImage;
	int bossCircleImage, bossHexagonImage, bossGearImage, bossSquareImage;
	int enemyNormalBulletImage, enemyExplodeBulletImage, enemyLargeBulletImage;

	int normalHP, normalHPFrame;
	int bossHP, bossHPFrame;

	int normalEffect;
public:
	void load();
	void release();
	int getTitleImage() const;
	int getPlayerImage(int) const;
	int getPlayerNormalBulletImage() const;

	int getCircleImage() const;
	int getHexagonImage() const;
	int getGearImage() const;
	int getSquareImage() const;

	int getBossCircleImage() const;
	int getBossHexagonImage() const;
	int getBossGearImage() const;
	int getBossSquareImage() const;

	int getEnemyNormalBulletImage() const;
	int getEnemyExplodeBulletImage() const;
	int getEnemyLargeBulletImage() const;

	int getNormalHP() const;
	int getNormalHPFrame() const;
	int getBossHP() const;
	int getBossHPFrame() const;

	int getNormalEffect() const;

	~CImage();
};

