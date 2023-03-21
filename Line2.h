#pragma once
#include "Define.h"
class CLine2
{
public:
	CLine2() = default;
	CLine2(LinePoint _L, LinePoint _R) :
	m_tLine(_L, _R) {}

	~CLine2() = default;

	MyLine Get_Line() const { return m_tLine; }

	void Render(HDC _dc);

private:
	MyLine m_tLine;
};

