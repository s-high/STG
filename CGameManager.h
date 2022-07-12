#pragma once
#include <memory>
#include "CPlayer.h"
#include "CObjectManager.h"
#include "CNWayPlayerWeapon.h"
#include "CNormalPlayerBulletFactory.h"
#include "CBaseEnemy.h"
#include "CNormalEnemy.h"
#include "CNormalEnemyBulletFactory.h"
#include "CRandomFlyMove.h"
#include "CStraightMove.h"
#include "CCollision.h"
#include "CBaseBoss.h"
#include "CNormalBoss.h"


#include "CDrawString.h"

class CSceneManager;

class CGameManager
{
public:
	static std::shared_ptr<CPlayer> pPlayer;
	static std::shared_ptr<CObjectManager> pPlayerBulletMananger;
	static std::shared_ptr<CObjectManager> pEnemyManager;
	static std::shared_ptr<CObjectManager> pEnemyBulletManager;
	static std::shared_ptr<CObjectManager> pBossManager;
	static std::shared_ptr<CObjectManager> pEffectManager;

	enum ePhase {
		Playing,
		Clear,
		GameOver,
	};
private:
	std::shared_ptr<CCollision> pCollision;
	ePhase currentPhase = ePhase::Playing;
	CSceneManager* pScnMgr;
public:
	CGameManager(CSceneManager*,int,int);
	void upDate();
	void render();
	void init();
	~CGameManager();
};

