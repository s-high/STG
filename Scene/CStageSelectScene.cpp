#include "CStageSelectScene.h"
#include "CSceneManager.h"
#include "CDrawString.h"

#include <string>

CStageSelectScene::CStageSelectScene(CSceneManager* pSceneMgr, CParameter& p) : CBaseScene(pSceneMgr)
{
	this->currentStage = 1;
	pX = SCREEN_WIDTH * 0.5 - this->PLAYER_SIZE * 0.5;
	pVX = 8;
	stageChangeAnimation = 0;
}

void CStageSelectScene::upDate() {
	int const ICON_TO_ICON = 200;
	int const MAX_STAGE_CHANGE_ANIMATION = 5;

	if (0 < stageChangeAnimation)stageChangeAnimation -= 1;
	if(pX < SCREEN_WIDTH * 0.5 - this->PLAYER_SIZE * 0.5)pX += pVX;
	else if (pX > SCREEN_WIDTH * 0.5 - this->PLAYER_SIZE * 0.5)pX -= pVX;

	if (CKeyFacade::getInstance()->getMomentKey(eKey::eRight) && currentStage < CSceneImage::STAGE_MAX) {
		currentStage += 1;
		pX -= ICON_TO_ICON;
		stageChangeAnimation = MAX_STAGE_CHANGE_ANIMATION;
	}

	if (CKeyFacade::getInstance()->getMomentKey(eKey::eLeft) && 0 < currentStage) {
		currentStage -= 1;
		pX += ICON_TO_ICON;
		stageChangeAnimation = MAX_STAGE_CHANGE_ANIMATION;
	}

	if (CKeyFacade::getInstance()->getMomentKey(eKey::eSpace)) {
		pX = SCREEN_WIDTH * 0.5 - this->PLAYER_SIZE * 0.5;
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
	int const ICON_SIZE = 120;

	// upper plate
	int const UP_INIT_POS = 15;
	double const UP_STR_RATE = 0.5;
	this->renderBackGround();
	DrawGraph(0, 0, CSceneImage::getInstance()->getStageSelectPlate(),true);
	CDrawString::getInstance()->drawString("stage select", UP_INIT_POS, UP_INIT_POS, UP_STR_RATE);

	// bottom plate
	int const BO_INIT_X = 100;
	int const BO_INIT_Y = 450;
	int const BO_ICON_TO_PLATE_X = 5;
	int const BO_ICON_TO_PLATE_Y = 100;
	int const BO_ICON_TO_STR_Y = 60;
	DrawGraph(BO_INIT_X + ICON_SIZE + BO_ICON_TO_PLATE_X, BO_INIT_Y + BO_ICON_TO_PLATE_Y, CSceneImage::getInstance()->getStageSelectPlate2(), TRUE);
	DrawGraph(BO_INIT_X, BO_INIT_Y - stageChangeAnimation, CSceneImage::getInstance()->getStageIcon(currentStage), TRUE);

	//  str
	std::string str;
	if (currentStage != 0)str = "stage " + std::to_string(currentStage);
	else str = "how to play";
	CDrawString::getInstance()->drawString(str.c_str(), BO_INIT_X + ICON_SIZE + BO_ICON_TO_PLATE_X, BO_INIT_Y + BO_ICON_TO_STR_Y, UP_STR_RATE);

	// stage icon
	int const IC_ICON_TO_ICON = 200;
	int const IC_ICON_CORRECTION = 50;
	for (int i = 0;i < CSceneImage::STAGE_MAX + 1;i++) {
		DrawGraph(
			SCREEN_WIDTH * 0.5 + (i - currentStage) * IC_ICON_TO_ICON - ICON_SIZE * 0.5,
			SCREEN_HEIGHT * 0.5 - ICON_SIZE - IC_ICON_CORRECTION, CSceneImage::getInstance()->getStageIcon(i), TRUE
		);
	}

	// player
	DrawGraph(int(pX), SCREEN_HEIGHT * 0.5, CImage::getInstance()->getPlayerImage(1), true);
}

CStageSelectScene::~CStageSelectScene()
{
}
