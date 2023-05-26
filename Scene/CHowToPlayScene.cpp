#include "CHowToPlayScene.h"
#include "CSceneManager.h"


CHowToPlayScene::CHowToPlayScene(CSceneManager* sm, CParameter& p) : CBaseScene(sm) {
	pBossVector.push_back(std::make_shared<CDisplayBoss>(this->CBOSS_X, this->BOSS_Y, std::make_shared<CCircleBossGraphic>()));
	pBossVector.push_back(std::make_shared<CDisplayBoss>(this->SBOSS_X, this->BOSS_Y, std::make_shared<CSquareBossGraphic>()));
	pBossVector.push_back(std::make_shared<CDisplayBoss>(this->HBOSS_X, this->BOSS_Y, std::make_shared<CHexagonBossGraphic>()));
	pBossVector.push_back(std::make_shared<CDisplayBoss>(this->GBOSS_X, this->BOSS_Y, std::make_shared<CGearBossGraphic>()));
}

void CHowToPlayScene::upDate() {
	if (CKeyFacade::getInstance()->getMomentKey(eKey::eSpace)) {
		this->pSceneManager->popScene();
	}
}

void CHowToPlayScene::render() {
	this->renderBackGround();

	double const STR_RATE = 0.5;
	int const STR_INTERVAL = 15;
	int const LETTER_SIZE = 32;
	int const SPACE_WIDTH = 16;
	int const PLAYER_SIZE = 32;

	// render "how to play" & plate
	int const HP_PLATE_INIT = 0;
	DrawGraph(HP_PLATE_INIT, HP_PLATE_INIT, CSceneImage::getInstance()->getStageSelectPlate(), true);
	CDrawString::getInstance()->drawString("how to play", STR_INTERVAL, STR_INTERVAL, STR_RATE);

	// render "wasd or arrow key to move"
	int const WO_INIT_X = 50;
	int const WO_INIT_Y = 100;
	CDrawString::getInstance()->drawString("wasd or arrow key to move", WO_INIT_X, WO_INIT_Y, STR_RATE);
	DrawGraph(int(this->CBOSS_X - PLAYER_SIZE * 0.5), int(WO_INIT_Y + LETTER_SIZE * 2.5), CImage::getInstance()->getPlayerImage(1), true);

	// render "beat the boss enemy"
	int const BT_INIT_X = 50;
	int const BT_INIT_Y = 300;
	CDrawString::getInstance()->drawString("beat the boss enemy", BT_INIT_X, BT_INIT_Y, STR_RATE);
	for (auto e : this->pBossVector)e->render();

	// render "press space to back"
	CDrawString::getInstance()->drawString(
		"press space to back",
		// "press space to back" -> letter = 16, space = 3
		SCREEN_WIDTH - (LETTER_SIZE * 16 + SPACE_WIDTH * 3) - STR_INTERVAL,
		SCREEN_HEIGHT - LETTER_SIZE - STR_INTERVAL,
		STR_RATE
	);

}

CHowToPlayScene::~CHowToPlayScene() {
}
