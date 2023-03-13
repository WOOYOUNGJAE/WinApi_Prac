#include "stdafx.h"
#include "Mouse.h"

CMouse::CMouse()
{
}

CMouse::~CMouse()
{
	Release();
}

void CMouse::Initialize()
{
	m_tPosInfo.fCX = 20.f;
	m_tPosInfo.fCY = 20.f;
}

void CMouse::Update()
{
	POINT tmpPoint{};

	GetCursorPos(&tmpPoint);

	ScreenToClient(g_hwnd, &tmpPoint);

	m_tPosInfo.fX = (tmpPoint.x);
	m_tPosInfo.fY = (tmpPoint.y);

	CObj::RenewRECT();

	ShowCursor(false);
}

void CMouse::LateUpdate()
{
}

void CMouse::Render(HDC _dc)
{
	Rectangle(_dc, m_rectInfo.left, m_rectInfo.top, m_rectInfo.right, m_rectInfo.bottom);
}


void CMouse::Release()
{
}
