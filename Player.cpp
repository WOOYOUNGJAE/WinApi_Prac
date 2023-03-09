#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::Initialize()
{
	m_tPosInfo = { WINCX * 0.5f, WINCY * 0.5f, 50, 50 };
	m_fMoveSpeed = 5.f;
}

void CPlayer::Initialize(list<CObj*>* _pBullet)
{
	m_tPosInfo = { WINCX * 0.5f, WINCY * 0.5f, 50, 50 };
	m_fMoveSpeed = 5.f;

	m_pBullet = _pBullet;
}

void CPlayer::Update()
{
	EnterKey();

	__super::UpdateRect();
}

void CPlayer::Render(HDC _hdc)
{
	Rectangle(_hdc,
		m_tRect.left,
		m_tRect.top,
		m_tRect.right,
		m_tRect.bottom);
}

void CPlayer::Release()
{
}

void CPlayer::EnterKey()
{
	if (GetAsyncKeyState(VK_LEFT))
	{		
		m_tPosInfo.fX -= m_fMoveSpeed;
	}
	else if (GetAsyncKeyState(VK_UP))
	{
		m_tPosInfo.fY -= m_fMoveSpeed;
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		m_tPosInfo.fX += m_fMoveSpeed;
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		m_tPosInfo.fY += m_fMoveSpeed;
	}
	// ÃÑ¾Ë
	else if (GetAsyncKeyState('W'))
	{
		m_pBullet->push_back(CreateBullet(MY_DIRECTION::UP));
	}
	else if (GetAsyncKeyState('A'))
	{
		m_pBullet->push_back(CreateBullet(MY_DIRECTION::LEFT));
	}
	else if (GetAsyncKeyState('S'))
	{
		m_pBullet->push_back(CreateBullet(MY_DIRECTION::DOWN));
	}
	else if (GetAsyncKeyState('D'))
	{
		m_pBullet->push_back(CreateBullet(MY_DIRECTION::RIGHT));
	}
	else if (GetAsyncKeyState('Q'))
	{
		m_pBullet->push_back(CreateBullet(MY_DIRECTION::LU));
	}
	else if (GetAsyncKeyState('E'))
	{
		m_pBullet->push_back(CreateBullet(MY_DIRECTION::RU));
	}
	else if (GetAsyncKeyState('Z'))
	{
		m_pBullet->push_back(CreateBullet(MY_DIRECTION::LD));
	}
	else if (GetAsyncKeyState('C'))
	{
		m_pBullet->push_back(CreateBullet(MY_DIRECTION::RD));
	}
	else if (GetAsyncKeyState(VK_SPACE))
	{
		m_pBullet->push_back(CreateBullet(MY_DIRECTION::LU));
		m_pBullet->push_back(CreateBullet(MY_DIRECTION::UP));
		m_pBullet->push_back(CreateBullet(MY_DIRECTION::RU));
	}


		
}

CObj* CPlayer::CreateBullet(MY_DIRECTION _eDir)
{
	CObj* pTmpBullet = new CBullet;

	pTmpBullet->Initialize();

	pTmpBullet->Set_Pos(m_tPosInfo.fX, m_tPosInfo.fY);
	pTmpBullet->Set_Dir(_eDir);

	return pTmpBullet;
}
