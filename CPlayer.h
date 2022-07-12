#pragma once
#include "CBaseObject.h"
#include "CCircle.h"
#include "DxLib.h"
#include "CImage.h"
#include "CPlayerMove.h"
#include "CBasePlayerWeapon.h"
#include "CRestrictOutOfScreen.h"

class CBaseEnemy;
class CBaseEnemyBullet;

class CPlayer :
	public CBaseObject
{
	std::shared_ptr<CBaseMove> pMove;
	std::shared_ptr<CBaseOutOfScreen> pOutOfScreen;
	std::shared_ptr<CBasePlayerWeapon> pWeapon;
public:
	CPlayer(double,double);
	void upDate();
	void render();
	void init();
	void setMove(std::shared_ptr<CBaseMove>);
	void setWeapon(std::shared_ptr<CBasePlayerWeapon>);
	void createPlayer(std::shared_ptr<CBaseMove>, std::shared_ptr<CBasePlayerWeapon>);

	void dispatch(std::shared_ptr<CBaseObject>);
	void hitObject(CBaseEnemy*);
	void hitObject(CBaseBoss*);
	void hitObject(CBaseEnemyBullet*);
	void deadProcess();
	~CPlayer();
};

