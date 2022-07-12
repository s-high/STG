#include "CTitleScene.h"
#include "CSceneManager.h"
#include "CDrawString.h"

CTitleScene::CTitleScene(CSceneManager* sm, CParameter& p) : CBaseScene(sm)
{

}

void CTitleScene::upDate() {
	if (CKeyFacade::getInstance()->getMomentKey(eKey::eSpace)) {
		CParameter p;
		pSceneManager->pushScene(eScene::eStageSelect, p);
	}
}

void CTitleScene::render() {
	this->renderBackGround();
	
	CDrawString::getInstance()->drawStringCorner("space shooting", 480, 200, 0.8);
	CDrawString::getInstance()->drawStringCorner("press space to play", 480, 400, 0.5);
}


CTitleScene::~CTitleScene()
{
}
