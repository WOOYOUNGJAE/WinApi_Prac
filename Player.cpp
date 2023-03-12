#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "Factory.h"

CPlayer::CPlayer(): m_pBulletSlot(nullptr)
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::Set_BulletSlot(list<CObj*>* _pBulletSlot)
{
	m_pBulletSlot = _pBulletSlot;
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

CObj* CPlayer::CreateBullet(MY_MOVEDIRECTION _eDir)
{
	CObj* pTmpBullet = new CBullet;
	pTmpBullet->Initialize();
	pTmpBullet->Set_Pos(m_tPosInfo.fX, m_tPosInfo.fY);
	pTmpBullet->Set_Dir(_eDir);
	return pTmpBullet;
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
	// bullet
	else if(GetAsyncKeyState('W'))
	{
		m_pBulletSlot->push_back(
			Factory<CBullet>::CreateObj(m_tPosInfo.fX, m_tPosInfo.fY, MY_MOVEDIRECTION::UP)
		);
	}
	else if(GetAsyncKeyState('D'))
	{
		m_pBulletSlot->push_back(
			Factory<CBullet>::CreateObj(m_tPosInfo.fX, m_tPosInfo.fY, MY_MOVEDIRECTION::RIGHT)
		);
	}
	else if(GetAsyncKeyState('A'))
	{
		m_pBulletSlot->push_back(
			Factory<CBullet>::CreateObj(m_tPosInfo.fX, m_tPosInfo.fY, MY_MOVEDIRECTION::LEFT)
		);
	}
	else if(GetAsyncKeyState('E'))
	{
		m_pBulletSlot->push_back(
			Factory<CBullet>::CreateObj(m_tPosInfo.fX, m_tPosInfo.fY, MY_MOVEDIRECTION::RU)
		);
	}
	else if(GetAsyncKeyState('Q'))
	{
		m_pBulletSlot->push_back(
			Factory<CBullet>::CreateObj(m_tPosInfo.fX, m_tPosInfo.fY, MY_MOVEDIRECTION::LU)
		);
	}
	else if(GetAsyncKeyState(VK_SPACE))
	{
		m_pBulletSlot->push_back(
			Factory<CBullet>::CreateObj(m_tPosInfo.fX, m_tPosInfo.fY, MY_MOVEDIRECTION::LU)
		);
		m_pBulletSlot->push_back(
			Factory<CBullet>::CreateObj(m_tPosInfo.fX, m_tPosInfo.fY, MY_MOVEDIRECTION::UP)
		);
		m_pBulletSlot->push_back(
			Factory<CBullet>::CreateObj(m_tPosInfo.fX, m_tPosInfo.fY, MY_MOVEDIRECTION::RU)
		);
	}
}
