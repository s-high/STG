#pragma once
#include "CBaseScene.h"
#include "CParameter.h"
#include "CSceneImage.h"
#include "CDrawString.h"
#include "CKeyFacade.h"

#include "CImage.h"
#include "CDisplayBoss.h"

class CHowToPlayScene :
	public CBaseScene {
	// boss graphic
	std::vector<std::shared_ptr<CDisplayBoss>> pBossVector;
	int const BOSS_Y = 450;
	int const CBOSS_X = 150;
	int const SBOSS_X = 350;
	int const HBOSS_X = 550;
	int const GBOSS_X = 750;

	// render letter
public:
	CHowToPlayScene(CSceneManager*, CParameter&);
	void upDate() override;
	void render() override;
	~CHowToPlayScene();
};

