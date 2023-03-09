#include "stdafx.h"
#include "Obj.h"

void CObj::UpdateRect()
{
	m_tRect.left = LONG(m_tPosInfo.fX - (m_tPosInfo.fCX * 0.5f));
	m_tRect.top = LONG(m_tPosInfo.fY - (m_tPosInfo.fCY * 0.5f));
	m_tRect.right = LONG(m_tPosInfo.fX + (m_tPosInfo.fCX * 0.5f));
	m_tRect.bottom = LONG(m_tPosInfo.fY + (m_tPosInfo.fCY * 0.5f));
}
