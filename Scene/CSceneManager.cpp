#include "CSceneManager.h"
#include "CStageSelectScene.h"
#include "CHowToPlayScene.h"

CSceneManager::CSceneManager()
{
	CParameter p;
	sceneStack.push(std::make_shared<CTitleScene>(this, p));
}

void CSceneManager::doScene() {
	sceneStack.top()->upDate();
	sceneStack.top()->render();
}

void CSceneManager::pushScene(eScene scene, CParameter& p) {
	switch (scene)
	{
	case eTitle:
		sceneStack.push(std::make_shared<CTitleScene>(this, p));
		break;
	case eStageSelect:
		sceneStack.push(std::make_shared<CStageSelectScene>(this, p));
		break;
	case eHowToPlay:
		sceneStack.push(std::make_shared<CHowToPlayScene>(this, p));
		break;
	case ePlay:
		sceneStack.push(std::make_shared<CPlayScene>(this, p));
		break;
	default:
		break;
	}
}

void CSceneManager::popScene() {
	sceneStack.pop();
}

CSceneManager::~CSceneManager()
{

}
