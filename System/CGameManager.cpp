#include "CGameManager.h"
#include "CSceneManager.h"

#include "CCircle1BossBehavior.h"
#include "CCircle2BossBehavior.h"
#include "CCircle3BossBehavior.h"
#include "CCircle4BossBehavior.h"
#include "CCircle5BossBehavior.h"
#include "CSquare1BossBehavior.h"
#include "CGear1BossBehavior.h"
#include "CHexagon1BossBehavior.h"

CGameManager::CGameManager(CSceneManager* pScnMgr,int stage,int way)
{
	this->pScnMgr = pScnMgr;
	init();
	
	switch (stage)
	{
	case 1:
		pBossManager->addObject(std::make_shared<CNormalBoss>(480, 800, std::make_shared<CCircle1BossBehavior>(),std::make_shared<CCircleBossGraphic>()));
		break;
	case 2:
		pBossManager->addObject(std::make_shared<CNormalBoss>(480, 800, std::make_shared<CCircle2BossBehavior>(), std::make_shared<CCircleBossGraphic>()));
		break;
	case 3:
		pBossManager->addObject(std::make_shared<CNormalBoss>(480, 900, std::make_shared<CSquare1BossBehavior>(), std::make_shared<CSquareBossGraphic>()));
		break;
	case 4:
		pBossManager->addObject(std::make_shared<CNormalBoss>(480, 700, std::make_shared<CGear1BossBehavior>(), std::make_shared<CGearBossGraphic>()));
		break;
	case 5:
		pBossManager->addObject(std::make_shared<CNormalBoss>(480, 800, std::make_shared<CCircle3BossBehavior>(), std::make_shared<CCircleBossGraphic>()));
		break;
	case 6:
		pBossManager->addObject(std::make_shared<CNormalBoss>(480, 800, std::make_shared<CCircle4BossBehavior>(), std::make_shared<CCircleBossGraphic>()));
		break;
	case 7:
		pBossManager->addObject(std::make_shared<CNormalBoss>(480 * 0.5, 800, std::make_shared<CCircle2BossBehavior>(), std::make_shared<CCircleBossGraphic>()));
		pBossManager->addObject(std::make_shared<CNormalBoss>(480 * 1.5, 800, std::make_shared<CCircle2BossBehavior>(), std::make_shared<CCircleBossGraphic>()));
		//pBossManager->addObject(std::make_shared<CNormalBoss>(480, 800, std::make_shared<CCircle3BossBehavior>(), std::make_shared<CCircleBossGraphic>()));
		break;
	case 8:
		pBossManager->addObject(std::make_shared<CNormalBoss>(480, 800, std::make_shared<CHexagon1BossBehavior>(), std::make_shared<CHexagonBossGraphic>()));
		//pBossManager->addObject(std::make_shared<CNormalBoss>(480, 800, std::make_shared<CCircle3BossBehavior>(), std::make_shared<CCircleBossGraphic>()));
		break;
	case 9:
		pBossManager->addObject(std::make_shared<CNormalBoss>(480, 1200, std::make_shared<CCircle5BossBehavior>(), std::make_shared<CCircleBossGraphic>()));
		//pBossManager->addObject(std::make_shared<CNormalBoss>(480, 800, std::make_shared<CCircle3BossBehavior>(), std::make_shared<CCircleBossGraphic>()));
		break;
	case 10:
		pBossManager->addObject(std::make_shared<CNormalBoss>(240, 800, std::make_shared<CCircle3BossBehavior>(), std::make_shared<CCircleBossGraphic>()));
		pBossManager->addObject(std::make_shared<CNormalBoss>(720, 800, std::make_shared<CCircle3BossBehavior>(), std::make_shared<CCircleBossGraphic>()));
		break;
	default:
		printfDx("CAUTION : No Such Stage");
		break;
	}

	// create
	this->pPlayer->setWeapon(std::make_shared<CNWayPlayerWeapon>(pPlayerBulletMananger,std::make_shared<CNormalPlayerBulletFactory>(),way));

	//Collision
	pCollision = std::make_shared<CCollision>(pPlayer, this->pPlayerBulletMananger, this->pEnemyManager, this->pEnemyBulletManager,this->pBossManager);
}

std::shared_ptr<CPlayer> CGameManager::pPlayer;
std::shared_ptr<CObjectManager> CGameManager::pPlayerBulletMananger;
std::shared_ptr<CObjectManager> CGameManager::pEnemyManager;
std::shared_ptr<CObjectManager> CGameManager::pEnemyBulletManager;
std::shared_ptr<CObjectManager> CGameManager::pBossManager;
std::shared_ptr<CObjectManager> CGameManager::pEffectManager;

void CGameManager::upDate() {
	switch (this->currentPhase)
	{
	case ePhase::Playing:
		CGameManager::pPlayerBulletMananger->upDate();
		CGameManager::pEnemyBulletManager->upDate();
		CGameManager::pEnemyManager->upDate();
		CGameManager::pBossManager->upDate();
		CGameManager::pPlayer->upDate();
		CGameManager::pCollision->upDate();
		CGameManager::pEffectManager->upDate();

		if (!pPlayer->getIsAlive())this->currentPhase = ePhase::GameOver;
		if (pBossManager->getSize() == 0)this->currentPhase = ePhase::Clear;

		break;
	case ePhase::Clear:
		pPlayerBulletMananger->upDate();
		pEnemyBulletManager->upDate();
		pEnemyManager->upDate();
		pBossManager->upDate();
		pPlayer->upDate();
		// pCollision->upDate();
		pEffectManager->upDate();

		if (CKeyFacade::getInstance()->getMomentKey(eKey::eSpace))this->pScnMgr->popScene();
		break;
	case ePhase::GameOver:
		pPlayerBulletMananger->upDate();
		pEnemyBulletManager->upDate();
		pEnemyManager->upDate();
		pBossManager->upDate();
		// pPlayer->upDate();
		// pCollision->upDate();
		pEffectManager->upDate();

		if (CKeyFacade::getInstance()->getMomentKey(eKey::eSpace))this->pScnMgr->popScene();
		break;
	default:
		break;
	}
}

void CGameManager::render() {
	switch (this->currentPhase)
	{
	case ePhase::Playing:
		pPlayerBulletMananger->render();
		pEnemyBulletManager->render();
		pEnemyManager->render();
		pBossManager->render();
		pPlayer->render();
		pEffectManager->render();
		break;
	case ePhase::Clear:
		pPlayerBulletMananger->render();
		pEnemyBulletManager->render();
		pEnemyManager->render();
		pBossManager->render();
		pPlayer->render();
		pEffectManager->render();

		CDrawString::getInstance()->drawStringCorner("stage clear", int(SCREEN_WIDTH * 0.5), 300, 1.0);
		CDrawString::getInstance()->drawStringCorner("press space", int(SCREEN_WIDTH * 0.5), 400, 0.5);
		break;
	case ePhase::GameOver:
		pPlayerBulletMananger->render();
		pEnemyBulletManager->render();
		pEnemyManager->render();
		pBossManager->render();
		// pPlayer->render();
		pEffectManager->render();

		CDrawString::getInstance()->drawStringCorner("game over", int(SCREEN_WIDTH * 0.5), 300, 1.0);
		CDrawString::getInstance()->drawStringCorner("press space", int(SCREEN_WIDTH * 0.5), 400, 0.5);

		break;
	default:
		break;
	}
}

void CGameManager::init() {
	CGameManager::pPlayer = std::make_shared<CPlayer>(480, 500);
	CGameManager::pPlayerBulletMananger = std::make_shared<CObjectManager>();
	CGameManager::pEnemyManager = std::make_shared<CObjectManager>();
	CGameManager::pEnemyBulletManager = std::make_shared<CObjectManager>();
	CGameManager::pBossManager = std::make_shared<CObjectManager>();
	CGameManager::pEffectManager = std::make_shared<CObjectManager>();
}

CGameManager::~CGameManager()
{
}
