#include "stdafx.h"
#include "Enemy.h"

CEnemy::CEnemy() 
{
}

CEnemy::~CEnemy()
{
	Release();
}

void CEnemy::Initialize()
{
	m_tPosInfo = { WINCX * 0.5f , DESTROYZONE_TOP + 50.f , 50, 20 };

	m_eMoveDir = MY_MOVEDIRECTION::RIGHT;
	m_fMoveSpeed = 8.f;
}

void CEnemy::Update()
{
	CheckWall();

	if (m_eMoveDir == MY_MOVEDIRECTION::LEFT)
	{
		m_tPosInfo.fX -= m_fMoveSpeed;
	}
	else if (m_eMoveDir == MY_MOVEDIRECTION::RIGHT)
	{
		m_tPosInfo.fX += m_fMoveSpeed;
	}

	CObj::RenewRECT();
}

void CEnemy::LateUpdate()
{
}

void CEnemy::Render(HDC _dc)
{
	Rectangle(_dc,
		m_rectInfo.left,
		m_rectInfo.top,
		m_rectInfo.right,
		m_rectInfo.bottom);
}

void CEnemy::Release()
{
}

void CEnemy::CheckWall()
{
	if (m_eMoveDir == MY_MOVEDIRECTION::LEFT)
	{
		if (m_tPosInfo.fX < DESTROYZONE_LEFT + m_tPosInfo.fCX * 0.5f)
		{
			m_eMoveDir = MY_MOVEDIRECTION::RIGHT;
		}
	}
	else if (m_eMoveDir == MY_MOVEDIRECTION::RIGHT)
	{
		if (m_tPosInfo.fX > DESTROYZONE_RIGHT - m_tPosInfo.fCX * 0.5f)
		{
			m_eMoveDir = MY_MOVEDIRECTION::LEFT;
		}
	}
}
