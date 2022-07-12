#pragma once
#include "CBaseScene.h"
#include "CParameter.h"
#include "CImage.h"
#include "CKeyFacade.h"

#include "CSceneImage.h"

class CSceneManager;

class CTitleScene :
	public CBaseScene
{

public:
	CTitleScene(CSceneManager*,CParameter&);
	void upDate() override;
	void render() override;
	~CTitleScene();
};

