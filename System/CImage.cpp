#include "CImage.h"



CImage::CImage()
{
	this->titleImage = this->myLoadGraph("./images/titleImage.png");
	this->myLoadDivGraph("./images/playerImage.png",3,3,1,32,32,this->playerImage);
	this->playerNormalBullet = this->myLoadGraph("./images/playerNormalBullet.png");

	this->enemyCircleImage = this->myLoadGraph("./images/circle.png");
	this->enemyHexagonImage = this->myLoadGraph("./images/hexagon.png");
	this->enemyGearImage = this->myLoadGraph("./images/gear.png");
	this->enemySquareImage = this->myLoadGraph("./images/square.png");

	this->enemyNormalBulletImage = this->myLoadGraph("./images/enemyNormalBullet.png");
	this->enemyExplodeBulletImage = this->myLoadGraph("./images/enemyExplodeBullet.png");
	this->enemyLargeBulletImage = this->myLoadGraph("./images/enemyLargeBullet.png");

	this->bossCircleImage = this->myLoadGraph("./images/circleBoss.png");
	this->bossHexagonImage = this->myLoadGraph("./images/hexagonBoss.png");
	this->bossGearImage = this->myLoadGraph("./images/gearBoss.png");
	this->bossSquareImage = this->myLoadGraph("./images/squareBoss.png");

	this->normalHP = this->myLoadGraph("./images/HP.png");
	this->normalHPFrame = this->myLoadGraph("./images/HPFrame.png");

	this->bossHP = this->myLoadGraph("./images/HPBoss.png");
	this->bossHPFrame = this->myLoadGraph("./images/HPBossFrame.png");

	this->normalEffect = this->myLoadGraph("./images/whiteEffect.png");
}

// getImage

int CImage::getTitleImage() const {
	return this->titleImage;
}

int CImage::getPlayerImage(int n) const {
	if (n <= -1 || 3 <= n)return -1;
	return this->playerImage[n];
}

int CImage::getPlayerNormalBulletImage() const {
	return this->playerNormalBullet;
}

int CImage::getCircleImage() const { return this->enemyCircleImage; }
int CImage::getHexagonImage() const { return this->enemyHexagonImage; }
int CImage::getGearImage() const { return this->enemyGearImage; }
int CImage::getSquareImage() const { return this->enemySquareImage; }

int CImage::getBossCircleImage() const { return this->bossCircleImage; }
int CImage::getBossHexagonImage() const { return this->bossHexagonImage; }
int CImage::getBossGearImage() const { return this->bossGearImage; }
int CImage::getBossSquareImage() const { return this->bossSquareImage; }

int CImage::getEnemyNormalBulletImage() const { return this->enemyNormalBulletImage; }
int CImage::getEnemyExplodeBulletImage() const { return this->enemyExplodeBulletImage; }
int CImage::getEnemyLargeBulletImage() const { return this->enemyLargeBulletImage; }

int CImage::getNormalHP() const { return this->normalHP; }
int CImage::getNormalHPFrame() const { return this->normalHPFrame; }
int CImage::getBossHP() const { return this->bossHP; }
int CImage::getBossHPFrame() const { return this->bossHPFrame; }

int CImage::getNormalEffect() const { return this->normalEffect; }

// method

int CImage::myLoadGraph(const char *FileName) {
	int handle = LoadGraph(FileName);
	this->imageHandles.push_back(handle);
	return handle;
}

int CImage::myLoadDivGraph(const char *FileName, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleArray) {
	int flag = LoadDivGraph(FileName, AllNum, XNum, YNum, XSize, YSize, HandleArray, TRUE);
	for (int i = 0;i < AllNum;i++) {
		this->imageHandles.push_back(HandleArray[i]);
	}
	return flag;
}

void CImage::load() {
	// pass
}

void CImage::release() {
	const int size = this->imageHandles.size();
	for (int i = 0; i < size; i++) {
		DeleteGraph(this->imageHandles[i]);
	}
	this->imageHandles.clear();
}

CImage::~CImage()
{
}
