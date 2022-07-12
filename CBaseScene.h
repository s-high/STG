#pragma once
#include <memory>
#include "DxLib.h"
#include "CRandom.h"
#include "extern.h"
#include <vector>

class CSceneManager;

class CBaseScene
{

	class CStar {
		const double MAX_SIZE = 4;
		const double MAX_VY = 2;

		double x, y;
		double size;
		double vy;
		unsigned int color;

	public:
		CStar() {
			this->x = CRandom::getInstance()->getRandom(SCREEN_WIDTH);
			this->y = CRandom::getInstance()->getRandom(SCREEN_HEIGHT);
			this->size = CRandom::getInstance()->getRandom() * MAX_SIZE;
			this->vy = CRandom::getInstance()->getRandom() * MAX_VY;
			this->color = GetColor(200, 200, CRandom::getInstance()->getRandom(0, 255));
		}

		void upDate() {
			this->checkHitWall();
			this->y += this->vy;
		}

		void render() {
			DrawCircleAA(this->x, this->y, this->size, 10, this->color, TRUE);
		}

		void checkHitWall() {
			if (this->y - this->size > SCREEN_HEIGHT)this->init();
		}

		void init() {
			this->x = CRandom::getInstance()->getRandom(SCREEN_WIDTH);
			this->y = 0;
			this->size = CRandom::getInstance()->getRandom() * MAX_SIZE;
			this->color = GetColor(200, 200, CRandom::getInstance()->getRandom(0, 255));
		}
	};
	
	std::vector<std::shared_ptr<CStar>> starVector;
protected:
	CSceneManager* pSceneManager;
	void renderBackGround();
public:
	CBaseScene(CSceneManager*);
	void virtual upDate() = 0;
	void virtual render() = 0;
	~CBaseScene();
};

