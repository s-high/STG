#include "CDrawString.h"



CDrawString::CDrawString()
{
	this->myLoadDivGraph("./images/letterMasenta.png", 36, 36, 1, 64, 64, this->letterMasentaImage);
	this->myLoadDivGraph("./images/letterWater.png", 36, 36, 1, 64, 64, this->letterWaterImage);

	this->letterMasentaImage[charToInt('m')] = this->myLoadGraph("./images/MMasenta.png");
	this->letterMasentaImage[charToInt('w')] = this->myLoadGraph("./images/WMasenta.png");
	this->letterWaterImage[charToInt('m')] = this->myLoadGraph("./images/MWater.png");
	this->letterWaterImage[charToInt('w')] = this->myLoadGraph("./images/WWater.png");
}

void CDrawString::drawString(const char* string, int x, int y, double rate) {
	if (string[0] == 0)return;
	this->drawChar(string[0], this->letterMasentaImage, x + 1, y + 1, rate);
	this->drawChar(string[0], this->letterWaterImage, x - 1, y - 1, rate);
	if (string[0] == 'm' || string[0] == 'w')this->drawString(string + 1, x + int((this->ORIGINAL_SIZE + 32) * rate), y, rate);
	else if(string[0] == ' ')this->drawString(string + 1, x + int((this->ORIGINAL_SIZE - 32) * rate), y, rate);
	else this->drawString(string + 1, x + int(this->ORIGINAL_SIZE * rate), y, rate);
}

void CDrawString::drawStringCorner(const char* string, int x, int y, double rate) {
	int countNon = this->count(string, 'm') + this->count(string, 'w') - this->count(string,' ');
	int len = int((this->length(string) * this->ORIGINAL_SIZE + countNon * this->ORIGINAL_SIZE * 0.5) * rate);
	this->drawString(string, int(x - len * 0.5), int(y - this->ORIGINAL_SIZE * rate * 0.5), rate);
}

int CDrawString::length(const char* string) {
	if (string[0] == 0)return 0;
	return 1 + this->length(string + 1);
}

int CDrawString::count(const char* string, char c) {
	if (string[0] == 0)return 0;
	if (string[0] == c)return 1 + this->count(string + 1, c);
	else return this->count(string + 1, c);
}

void CDrawString::drawChar(const char c, int* image, int x, int y, double rate) {
	if (c == ' ')return;
	if(c == 'w' || c == 'm')DrawExtendGraph(x, y, x + int(ORIGINAL_SIZE * rate * 1.5), y + int(ORIGINAL_SIZE * rate), image[charToInt(c)], true);
	else DrawExtendGraph(x, y, x + int(ORIGINAL_SIZE * rate), y + int(ORIGINAL_SIZE * rate), image[charToInt(c)], true);
}

int CDrawString::charToInt(const char c) {
	if ('0' <= c && c <= '9') {
		return c - '0';
	}
	else {
		return c - 'a' + 10;
	}
}

// method



int CDrawString::myLoadGraph(const char *FileName) {
	int handle = LoadGraph(FileName);
	this->imageHandles.push_back(handle);
	return handle;
}

int CDrawString::myLoadDivGraph(const char *FileName, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleArray) {
	int flag = LoadDivGraph(FileName, AllNum, XNum, YNum, XSize, YSize, HandleArray, TRUE);
	for (int i = 0;i < AllNum;i++) {
		this->imageHandles.push_back(HandleArray[i]);
	}
	return flag;
}

void CDrawString::load() {
	// pass
}

void CDrawString::release() {
	const int size = this->imageHandles.size();
	for (int i = 0; i < size; i++) {
		DeleteGraph(this->imageHandles[i]);
	}
	this->imageHandles.clear();
}


CDrawString::~CDrawString()
{
}
