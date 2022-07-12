#include "CHowToPlayScene.h"
#include "CSceneManager.h"


CHowToPlayScene::CHowToPlayScene(CSceneManager* sm, CParameter& p) : CBaseScene(sm)
{
	pBossVector.push_back(std::make_shared<CDisplayBoss>(150,450,std::make_shared<CCircleBossGraphic>()));
	pBossVector.push_back(std::make_shared<CDisplayBoss>(350, 450, std::make_shared<CSquareBossGraphic>()));
	pBossVector.push_back(std::make_shared<CDisplayBoss>(550, 450, std::make_shared<CHexagonBossGraphic>()));
	pBossVector.push_back(std::make_shared<CDisplayBoss>(750, 450, std::make_shared<CGearBossGraphic>()));
}

void CHowToPlayScene::upDate() {
	if (CKeyFacade::getInstance()->getMomentKey(eKey::eSpace)) {
		this->pSceneManager->popScene();
	}
}

void CHowToPlayScene::render() {
	this->renderBackGround();
	DrawGraph(0, 0, CSceneImage::getInstance()->getStageSelectPlate(), true);
	CDrawString::getInstance()->drawString("how to play", 15, 15, 0.5);

	CDrawString::getInstance()->drawString("wasd or arrow key to move", 50, 100, 0.5);
	DrawGraph(100, 160, CImage::getInstance()->getPlayerImage(1), true);

	CDrawString::getInstance()->drawString("beat the boss enemy", 50, 300, 0.5);
	for (auto e : this->pBossVector)e->render();

	CDrawString::getInstance()->drawString("press space to back", 380, 580, 0.5);

}

CHowToPlayScene::~CHowToPlayScene()
{
}
