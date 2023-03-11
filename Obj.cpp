#include "stdafx.h"
#include "Obj.h"

CObj::CObj() :
	m_rectInfo{}, m_tPosInfo{}, m_eMoveDir(MY_MOVEDIRECTION::DIR_END),
	m_fMoveSpeed(0)
{
}

CObj::~CObj()
{
}

void CObj::RenewRECT()
{
	m_rectInfo.left = LONG(m_tPosInfo.fX - m_tPosInfo.fCX * 0.5f);
	m_rectInfo.top = LONG(m_tPosInfo.fY - m_tPosInfo.fCY * 0.5f);
	m_rectInfo.right = LONG(m_tPosInfo.fX + m_tPosInfo.fCX * 0.5f);
	m_rectInfo.bottom = LONG(m_tPosInfo.fY + m_tPosInfo.fCY * 0.5f);
}