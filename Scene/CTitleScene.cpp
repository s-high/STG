#include "CTitleScene.h"
#include "CSceneManager.h"
#include "CDrawString.h"

CTitleScene::CTitleScene(CSceneManager* sm, CParameter& p) : CBaseScene(sm) {

}

void CTitleScene::upDate() {
	if (CKeyFacade::getInstance()->getMomentKey(eKey::eSpace)) {
		CParameter p;
		pSceneManager->pushScene(eScene::eStageSelect, p);
	}
}

void CTitleScene::render() {
	this->renderBackGround();

	// space shooting
	int const SS_INIT_Y = 200;
	double const SS_RATE = 0.8;
	CDrawString::getInstance()->drawStringCorner("space shooting", SCREEN_WIDTH * 0.5, SS_INIT_Y, SS_RATE);

	// press space to play
	int const PS_INIT_Y = 400;
	double const PS_RATE = 0.5;
	CDrawString::getInstance()->drawStringCorner("press space to play", SCREEN_WIDTH * 0.5, PS_INIT_Y, PS_RATE);
}


CTitleScene::~CTitleScene() {
}
