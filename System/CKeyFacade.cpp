#include "CKeyFacade.h"



CKeyFacade::CKeyFacade()
{
	GetHitKeyStateAll(this->keyBuff);
	GetHitKeyStateAll(this->prevKeyBuff);
	
	this->keyConfig[0].push_back(KEY_INPUT_D);
	this->keyConfig[1].push_back(KEY_INPUT_S);
	this->keyConfig[2].push_back(KEY_INPUT_A);
	this->keyConfig[3].push_back(KEY_INPUT_W);
	this->keyConfig[4].push_back(KEY_INPUT_SPACE);

	this->keyConfig[0].push_back(KEY_INPUT_RIGHT);
	this->keyConfig[1].push_back(KEY_INPUT_DOWN);
	this->keyConfig[2].push_back(KEY_INPUT_LEFT);
	this->keyConfig[3].push_back(KEY_INPUT_UP);
}

void CKeyFacade::upDate() {
	for (int i = 0;i < 256;i++)this->prevKeyBuff[i] = this->keyBuff[i];
	GetHitKeyStateAll(keyBuff);
}

bool CKeyFacade::getKey(eKey k) {
	for (int i = 0;i < this->keyConfig[int(k)].size();i++) {
		if (this->keyBuff[this->keyConfig[int(k)].at(i)])return true;
	}
	return false;
}

bool CKeyFacade::getMomentKey(eKey k) {
	for (int i = 0;i < this->keyConfig[int(k)].size();i++) {
		if (this->keyBuff[this->keyConfig[int(k)].at(i)] && !this->prevKeyBuff[this->keyConfig[int(k)].at(i)])return true;
	}
	return false;
}

CKeyFacade::~CKeyFacade()
{
}
