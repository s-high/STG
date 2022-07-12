#pragma once
#include "CBaseScene.h"
#include "CParameter.h"
#include "CSceneImage.h"
#include "CDrawString.h"
#include "CKeyFacade.h"

#include "CImage.h"
#include "CDisplayBoss.h"

class CHowToPlayScene :
	public CBaseScene
{
	std::vector<std::shared_ptr<CDisplayBoss>> pBossVector;
public:
	CHowToPlayScene(CSceneManager*, CParameter&);
	void upDate() override;
	void render() override;
	~CHowToPlayScene();
};

