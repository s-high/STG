#include "CPlayScene.h"
#include "CSceneImage.h"
#include "CDrawString.h"
#include <string>

CPlayScene::CPlayScene(CSceneManager* sm, CParameter& p) : CBaseScene(sm) {
	this->stage = p.get("stage");
	pGameManager = std::make_shared<CGameManager>(sm, this->stage, p.get("way"));
}

void CPlayScene::upDate() {
	pGameManager->upDate();
}

void CPlayScene::render() {
	// background
	this->renderBackGround();

	// game object
	pGameManager->render();

	// plate
	int const STR_INIT = 15;
	double const STR_RATE = 0.5;
	DrawGraph(0, 0, CSceneImage::getInstance()->getStagePlate(), true);
	std::string str = "stage " + std::to_string(this->stage);

	CDrawString::getInstance()->drawString(str.c_str(), STR_INIT, STR_INIT, STR_RATE);
}

CPlayScene::~CPlayScene() {
}
