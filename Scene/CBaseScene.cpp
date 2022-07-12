#include "CBaseScene.h"



CBaseScene::CBaseScene(CSceneManager *sm)
{
	this->pSceneManager = sm;
	for (int i = 0;i < 50;i++)this->starVector.push_back(std::make_shared<CStar>());
}

void CBaseScene::renderBackGround() {
	SetBackgroundColor(0, 40, 100);
	for (std::shared_ptr<CBaseScene::CStar> s : this->starVector) {
		s->upDate();
		s->render();
	}
}



CBaseScene::~CBaseScene()
{
}
