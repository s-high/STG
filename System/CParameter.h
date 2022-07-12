#pragma once
#include <map>
#include "DxLib.h"

class CParameter
{
	std::map<std::string, int> parameter;
public:
	CParameter();
	void add(std::string, int);
	int get(std::string);
	~CParameter();
};

