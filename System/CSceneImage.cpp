#include "CSceneImage.h"



CSceneImage::CSceneImage()
{
	this->stageSelectPlate = this->myLoadGraph("./images/stageSelectPlate.png");
	this->stageSelectPlate2 = this->myLoadGraph("./images/stagePlate2.png");
	this->stagePlate = this->myLoadGraph("./images/stagePlate.png");

	this->myLoadDivGraph("images/stageIcon.png", this->STAGE_MAX + 1, this->STAGE_MAX + 1, 1, 120, 120, this->stageIcon);
}

int CSceneImage::getStageSelectPlate() const { return this->stageSelectPlate; }
int CSceneImage::getStageSelectPlate2() const { return this->stageSelectPlate2; }
int CSceneImage::getStagePlate() const { return this->stagePlate; }
int CSceneImage::getStageIcon(int n) const { return this->stageIcon[n]; }

// method

int CSceneImage::myLoadGraph(const char *FileName) {
	int handle = LoadGraph(FileName);
	this->imageHandles.push_back(handle);
	return handle;
}

int CSceneImage::myLoadDivGraph(const char *FileName, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleArray) {
	int flag = LoadDivGraph(FileName, AllNum, XNum, YNum, XSize, YSize, HandleArray, TRUE);
	for (int i = 0;i < AllNum;i++) {
		this->imageHandles.push_back(HandleArray[i]);
	}
	return flag;
}

void CSceneImage::load() {
	// pass
}

void CSceneImage::release() {
	const int size = this->imageHandles.size();
	for (int i = 0; i < size; i++) {
		DeleteGraph(this->imageHandles[i]);
	}
	this->imageHandles.clear();
}
CSceneImage::~CSceneImage()
{
}
