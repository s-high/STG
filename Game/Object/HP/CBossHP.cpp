#include "CBossHP.h"



CBossHP::CBossHP(int hp) : CBaseHP(hp)
{
}

void CBossHP::render(double x, double y) {
	DrawGraph(int(x - this->SIZE * 0.5), int(y - this->SIZE * 0.5), CImage::getInstance()->getBossHPFrame(), true);

	double percent = this->getPercent();
	int n = int(percent * 8 + 1);

	for (int i = 0;i < n;i++) {
		DrawRotaGraph(int(x), int(y), 1.0, M_PI * 0.25 * i, CImage::getInstance()->getBossHP(), true);
	}
}

CBossHP::~CBossHP()
{
}
