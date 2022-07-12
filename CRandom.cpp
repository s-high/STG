#include "CRandom.h"



CRandom::CRandom()
{
}

int CRandom::getRandom(int n) {
	return GetRand(n);
}

int CRandom::getRandom(int n, int m) {
	if (m < n)return getRandom(m, n);
	return GetRand(m - n) + (m - n);
}

double CRandom::getRandom() {
	return GetRand(1000000) * 0.000001;
}

double CRandom::getRandomAngle() {
	return CRandom::getRandom() * 2 * M_PI;
}

CRandom::~CRandom()
{
}
