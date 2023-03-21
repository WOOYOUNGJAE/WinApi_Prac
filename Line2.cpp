#include "stdafx.h"
#include "Line2.h"

void CLine2::Render(HDC _dc)
{
	MoveToEx(_dc, (int)m_tLine.L_Point.fX, (int)m_tLine.L_Point.fY, nullptr);

	LineTo(_dc, (int)m_tLine.R_Point.fX, (int)m_tLine.R_Point.fY);
}
