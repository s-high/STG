#pragma once
#include <stack>
#include <memory>

#include "CParameter.h"

#include "eScene.h"
#include "CBaseScene.h"
#include "CTitleScene.h"
#include "CPlayScene.h"

class CSceneManager
{
	std::stack<std::shared_ptr<CBaseScene>> sceneStack;
public:
	CSceneManager();
	void pushScene(eScene, CParameter&);
	void popScene();
	void doScene();
	~CSceneManager();
};

