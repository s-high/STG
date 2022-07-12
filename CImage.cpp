#include "CImage.h"



CImage::CImage()
{
	titleImage = myLoadGraph("./images/titleImage.png");
	myLoadDivGraph("./images/playerImage.png",3,3,1,32,32,this->playerImage);
	playerNormalBullet = myLoadGraph("./images/playerNormalBullet.png");

	enemyCircleImage = myLoadGraph("./images/circle.png");
	enemyHexagonImage = myLoadGraph("./images/hexagon.png");
	enemyGearImage = myLoadGraph("./images/gear.png");
	enemySquareImage = myLoadGraph("./images/square.png");

	enemyNormalBulletImage = myLoadGraph("./images/enemyNormalBullet.png");
	enemyExplodeBulletImage = myLoadGraph("./images/enemyExplodeBullet.png");
	enemyLargeBulletImage = myLoadGraph("./images/enemyLargeBullet.png");

	bossCircleImage = myLoadGraph("./images/circleBoss.png");
	bossHexagonImage = myLoadGraph("./images/hexagonBoss.png");
	bossGearImage = myLoadGraph("./images/gearBoss.png");
	bossSquareImage = myLoadGraph("./images/squareBoss.png");

	normalHP = myLoadGraph("./images/HP.png");
	normalHPFrame = myLoadGraph("./images/HPFrame.png");

	bossHP = myLoadGraph("./images/HPBoss.png");
	bossHPFrame = myLoadGraph("./images/HPBossFrame.png");

	normalEffect = myLoadGraph("./images/whiteEffect.png");
}

// getImage

int CImage::getTitleImage() const {
	return titleImage;
}

int CImage::getPlayerImage(int n) const {
	if (n <= -1 || 3 <= n)return -1;
	return this->playerImage[n];
}

int CImage::getPlayerNormalBulletImage() const {
	return playerNormalBullet;
}

int CImage::getCircleImage() const { return enemyCircleImage; }
int CImage::getHexagonImage() const { return enemyHexagonImage; }
int CImage::getGearImage() const { return enemyGearImage; }
int CImage::getSquareImage() const { return enemySquareImage; }

int CImage::getBossCircleImage() const { return bossCircleImage; }
int CImage::getBossHexagonImage() const { return bossHexagonImage; }
int CImage::getBossGearImage() const { return bossGearImage; }
int CImage::getBossSquareImage() const { return bossSquareImage; }

int CImage::getEnemyNormalBulletImage() const { return enemyNormalBulletImage; }
int CImage::getEnemyExplodeBulletImage() const { return enemyExplodeBulletImage; }
int CImage::getEnemyLargeBulletImage() const { return enemyLargeBulletImage; }

int CImage::getNormalHP() const { return normalHP; }
int CImage::getNormalHPFrame() const { return normalHPFrame; }
int CImage::getBossHP() const { return bossHP; }
int CImage::getBossHPFrame() const { return bossHPFrame; }

int CImage::getNormalEffect() const { return normalEffect; }

// method

int CImage::myLoadGraph(const char *FileName) {
	int handle = LoadGraph(FileName);
	imageHandles.push_back(handle);
	return handle;
}

int CImage::myLoadDivGraph(const char *FileName, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleArray) {
	int flag = LoadDivGraph(FileName, AllNum, XNum, YNum, XSize, YSize, HandleArray, TRUE);
	for (int i = 0;i < AllNum;i++) {
		imageHandles.push_back(HandleArray[i]);
	}
	return flag;
}

void CImage::load() {
	// pass
}

void CImage::release() {
	const int size = imageHandles.size();
	for (int i = 0; i < size; i++) {
		DeleteGraph(imageHandles[i]);
	}
	imageHandles.clear();
}

CImage::~CImage()
{
}
