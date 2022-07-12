#include "CBaseMove.h"



CBaseMove::CBaseMove()
{
}

void CBaseMove::move(CBaseBoss* o) { this->move((CBaseObject*)o); }

CBaseMove::~CBaseMove()
{
}
