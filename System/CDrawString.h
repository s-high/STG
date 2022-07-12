#pragma once
#include "CSingleton.h"
#include "DxLib.h"
#include <vector>


class CDrawString :
	public CSingleton<CDrawString>
{
	friend CSingleton<CDrawString>;
	CDrawString();

	int myLoadGraph(const char*);
	int myLoadDivGraph(const char*, int, int, int, int, int, int*);
	std::vector<int> imageHandles;

	int letterMasentaImage[36];
	int letterWaterImage[36];

	double const ORIGINAL_SIZE = 64;
	void drawChar(const char, int*, int, int, double);
	int charToInt(const char);
	int length(const char*);
	int count(const char*, char);
public:
	void load();
	void release();

	void drawString(const char*, int, int, double);
	void drawStringCorner(const char*, int, int, double);

	~CDrawString();
};

