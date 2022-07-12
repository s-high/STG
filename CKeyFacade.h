#pragma once
#include "CSingleton.h"
#include "DxLib.h"
#include "eKey.h"
#include <vector>

class CKeyFacade : public CSingleton<CKeyFacade>
{
	CKeyFacade();
	friend CSingleton<CKeyFacade>;
private:
	char keyBuff[256];
	char prevKeyBuff[256];
	std::vector<unsigned char> keyConfig[eKeyNumber];
public:
	bool getKey(eKey);
	bool getMomentKey(eKey);
	void upDate();
	~CKeyFacade();
};

