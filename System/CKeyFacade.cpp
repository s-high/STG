#include "CKeyFacade.h"



CKeyFacade::CKeyFacade()
{
	GetHitKeyStateAll(this->keyBuff);
	GetHitKeyStateAll(this->prevKeyBuff);
	
	
	this->keyConfig[int(eKey::eRight)].push_back(KEY_INPUT_D);
	this->keyConfig[int(eKey::eDown)].push_back(KEY_INPUT_S);
	this->keyConfig[int(eKey::eLeft)].push_back(KEY_INPUT_A);
	this->keyConfig[int(eKey::eUp)].push_back(KEY_INPUT_W);
	this->keyConfig[int(eKey::eSpace)].push_back(KEY_INPUT_SPACE);

	this->keyConfig[int(eKey::eRight)].push_back(KEY_INPUT_RIGHT);
	this->keyConfig[int(eKey::eDown)].push_back(KEY_INPUT_DOWN);
	this->keyConfig[int(eKey::eLeft)].push_back(KEY_INPUT_LEFT);
	this->keyConfig[int(eKey::eUp)].push_back(KEY_INPUT_UP);
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
