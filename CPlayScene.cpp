#include "CPlayScene.h"
#include "CSceneImage.h"
#include "CDrawString.h"
#include <string>

CPlayScene::CPlayScene(CSceneManager* sm, CParameter& p) : CBaseScene(sm)
{
	this->stage = p.get("stage");
	pGameManager = std::make_shared<CGameManager>(sm,this->stage,p.get("way"));
}

void CPlayScene::upDate() {
	pGameManager->upDate();
}

void CPlayScene::render() {
	this->renderBackGround();
	pGameManager->render();

	DrawGraph(0, 0, CSceneImage::getInstance()->getStagePlate(), true);
	std::string str = "stage " + std::to_string(this->stage);

	CDrawString::getInstance()->drawString(str.c_str(), 15, 15, 0.5);
}

CPlayScene::~CPlayScene()
{
}
