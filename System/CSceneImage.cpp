#include "CSceneImage.h"



CSceneImage::CSceneImage()
{
	stageSelectPlate = myLoadGraph("./images/stageSelectPlate.png");
	stageSelectPlate2 = myLoadGraph("./images/stagePlate2.png");
	stagePlate = myLoadGraph("./images/stagePlate.png");

	myLoadDivGraph("images/stageIcon.png", STAGE_MAX + 1, STAGE_MAX + 1, 1, 120, 120, stageIcon);
}

int CSceneImage::getStageSelectPlate() const { return stageSelectPlate; }
int CSceneImage::getStageSelectPlate2() const { return stageSelectPlate2; }
int CSceneImage::getStagePlate() const { return stagePlate; }
int CSceneImage::getStageIcon(int n) const { return stageIcon[n]; }

// method

int CSceneImage::myLoadGraph(const char *FileName) {
	int handle = LoadGraph(FileName);
	imageHandles.push_back(handle);
	return handle;
}

int CSceneImage::myLoadDivGraph(const char *FileName, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleArray) {
	int flag = LoadDivGraph(FileName, AllNum, XNum, YNum, XSize, YSize, HandleArray, TRUE);
	for (int i = 0;i < AllNum;i++) {
		imageHandles.push_back(HandleArray[i]);
	}
	return flag;
}

void CSceneImage::load() {
	// pass
}

void CSceneImage::release() {
	const int size = imageHandles.size();
	for (int i = 0; i < size; i++) {
		DeleteGraph(imageHandles[i]);
	}
	imageHandles.clear();
}
CSceneImage::~CSceneImage()
{
}
