#pragma once
#include "CSingleton.h"
#include <vector>
#include "DxLib.h"

class CSceneImage : public CSingleton<CSceneImage>
{

	friend CSingleton<CSceneImage>;
	CSceneImage();

	int myLoadGraph(const char*);
	int myLoadDivGraph(const char*, int, int, int, int, int, int*);
	std::vector<int> imageHandles;

	int stageSelectPlate, stageSelectPlate2;
	int stagePlate;
public:
	int const static STAGE_MAX = 10;
private:
	int stageIcon[CSceneImage::STAGE_MAX + 1];

public:
	void load();
	void release();

	int getStageSelectPlate() const;
	int getStageSelectPlate2() const;
	int getStagePlate() const;
	int getStageIcon(int) const;

	~CSceneImage();
};

