#include "CStageSelectScene.h"
#include "CSceneManager.h"
#include "CDrawString.h"

#include <string>

CStageSelectScene::CStageSelectScene(CSceneManager* pSceneMgr, CParameter& p) : CBaseScene(pSceneMgr)
{
	this->currentStage = 1;
	pX = SCREEN_WIDTH / 2 - 16;
	pVX = 8;
	stageChangeAnimation = 0;
}

void CStageSelectScene::upDate() {
	if (0 < stageChangeAnimation)stageChangeAnimation -= 1;
	if(pX < SCREEN_WIDTH * 0.5 - 16)pX += pVX;
	else if (pX > SCREEN_WIDTH * 0.5 - 16)pX -= pVX;

	if (CKeyFacade::getInstance()->getMomentKey(eKey::eRight) && currentStage < CSceneImage::STAGE_MAX) {
		currentStage += 1;
		pX -= 200;
		stageChangeAnimation = 5;
	}

	if (CKeyFacade::getInstance()->getMomentKey(eKey::eLeft) && 0 < currentStage) {
		currentStage -= 1;
		pX += 200;
		stageChangeAnimation = 5;
	}

	if (CKeyFacade::getInstance()->getMomentKey(eKey::eSpace)) {
		pX = SCREEN_WIDTH * 0.5 - 16;
		CParameter p;
		if (currentStage == 0) {
			pSceneManager->pushScene(eScene::eHowToPlay, p);
		}else {
			p.add("stage", currentStage);
			int way = 3;
			if (CKeyFacade::getInstance()->getKey(eKey::eDown) && CKeyFacade::getInstance()->getKey(eKey::eUp))way += 4;
			p.add("way", way);
			pSceneManager->pushScene(eScene::ePlay, p);
		}
	}
}

void CStageSelectScene::render() {
	this->renderBackGround();
	//SetBackgroundColor(10, 20, 60);
	DrawGraph(0, 0, CSceneImage::getInstance()->getStageSelectPlate(),true);
	CDrawString::getInstance()->drawString("stage select", 15, 15, 0.5);

	DrawGraph(100 + 125, 550, CSceneImage::getInstance()->getStageSelectPlate2(), TRUE);
	DrawGraph(100, 450 - stageChangeAnimation, CSceneImage::getInstance()->getStageIcon(currentStage), TRUE);
	std::string str;
	if (currentStage != 0)str = "stage " + std::to_string(currentStage);
	else str = "how to play";
	CDrawString::getInstance()->drawString(str.c_str(), 225, 510, 0.5);


	for (int i = 0;i < CSceneImage::STAGE_MAX + 1;i++) {
		DrawGraph(SCREEN_WIDTH / 2 + (i - currentStage) * 200 - 60, SCREEN_HEIGHT / 2 - 120 - 50, CSceneImage::getInstance()->getStageIcon(i), TRUE);
	}

	DrawGraph(pX, 120 + 200, CImage::getInstance()->getPlayerImage(1), true);
}

CStageSelectScene::~CStageSelectScene()
{
}
