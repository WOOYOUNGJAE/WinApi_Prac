#include "stdafx.h"
#include "Player.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::Initialize()
{
	m_tPosInfo = { WINCX * 0.5f, WINCY * 0.5f, 100.f, 100.f };
	m_fMoveSpeed = 5.f;
}

void CPlayer::Update()
{
	GetKey();

	CObj::RenewRECT();
}

void CPlayer::LateUpdate()
{
}

void CPlayer::Render(HDC _dc)
{
	Rectangle(_dc, m_rectInfo.left, m_rectInfo.top, m_rectInfo.right, m_rectInfo.bottom);
}

void CPlayer::Release()
{
}

void CPlayer::GetKey()
{
	if (GetAsyncKeyState(VK_UP))
	{
		m_tPosInfo.fY -= m_fMoveSpeed;
	}
	else if(GetAsyncKeyState(VK_RIGHT))
	{
		m_tPosInfo.fX += m_fMoveSpeed;
	}
	else if(GetAsyncKeyState(VK_DOWN))
	{
		m_tPosInfo.fY += m_fMoveSpeed;
	}
	else if(GetAsyncKeyState(VK_LEFT))
	{
		m_tPosInfo.fX -= m_fMoveSpeed;
	}
}
