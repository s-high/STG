#include "CNormalHP.h"



CNormalHP::CNormalHP(int hp) : CBaseHP(hp)
{

}


void CNormalHP::render(double x, double y) {
	DrawGraph(int(x - this->SIZE * 0.5), int(y - this->SIZE * 0.5), CImage::getInstance()->getNormalHPFrame(), true);

	double percent = this->getPercent();
	int n = int(percent * 4 + 1);
	
	for (int i = 0;i < n;i++) {
		DrawRotaGraph(int(x), int(y), 1.0,M_PI * 0.5 * i,CImage::getInstance()->getNormalHP(),true);
	}
}

CNormalHP::~CNormalHP()
{
}
