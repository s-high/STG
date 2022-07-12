#pragma once
#include "CBaseScene.h"
#include "CParameter.h"
#include "CGameManager.h"

class CSceneManager;

class CPlayScene :
	public CBaseScene
{
	std::shared_ptr<CGameManager> pGameManager;
	int stage;
public:
	CPlayScene(CSceneManager*, CParameter&);
	void upDate();
	void render();
	~CPlayScene();
};

