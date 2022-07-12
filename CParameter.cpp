#include "CParameter.h"



CParameter::CParameter()
{
}

void CParameter::add(std::string key, int value) {
	parameter[key] = value;
}

int CParameter::get(std::string key) {
	try {
		return parameter[key];
	}
	catch (const std::exception& e) {
		printfDx("CParameter::get(std::string)");
		printfDx(" | No Such Key");
	}
}

CParameter::~CParameter()
{
}
