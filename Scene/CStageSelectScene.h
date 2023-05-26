#pragma once
#include "CBaseScene.h"
#include "CParameter.h"
#include "CKeyFacade.h"

class CSceneManager;

class CStageSelectScene :
	public CBaseScene
{
	int currentStage;
	float pX, pVX;
	int stageChangeAnimation;
	int const PLAYER_SIZE = 32;
public:
	CStageSelectScene(CSceneManager*, CParameter&);
	void upDate() override;
	void render() override;

	~CStageSelectScene();
};

