#pragma once
#include "CObjectManager.h"
#include "CBaseShape.h"
#include "CRect.h"
#include "CPlayer.h"
#include "CBaseObject.h"

class CCollision
{
	std::shared_ptr<CPlayer> pPlayer;
	std::shared_ptr<CObjectManager> pPBMgr;
	std::shared_ptr<CObjectManager> pEMgr;
	std::shared_ptr<CObjectManager> pEBMgr;
	std::shared_ptr<CObjectManager> pBMgr;

	bool isHitObjectAndObject(std::shared_ptr<CBaseObject>, std::shared_ptr<CBaseObject>);
	void checkObjectAndObject(std::vector<std::shared_ptr<CBaseObject>>, std::vector<std::shared_ptr<CBaseObject>>);
	void checkObjectAndObject(std::shared_ptr<CBaseObject>, std::vector<std::shared_ptr<CBaseObject>>);
public:
	CCollision(std::shared_ptr<CPlayer>, std::shared_ptr<CObjectManager>, std::shared_ptr<CObjectManager>, std::shared_ptr<CObjectManager>, std::shared_ptr<CObjectManager>);
	void upDate();
	~CCollision();
};

