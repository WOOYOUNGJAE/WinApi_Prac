#include "stdafx.h"
#include "Enemy.h"

CEnemy::CEnemy()
{
}

CEnemy::~CEnemy()
{
}

void CEnemy::Initialize()
{
	m_tPosInfo = { WINCX * 0.5f ,50.f , 50, 20 };
	//m_tPosInfo = { WINCX * 0.5f, WINCY * 0.5f , 50, 50 };

	m_fMoveSpeed = 8.f;

	m_eMoveDir = MY_DIRECTION::RIGHT;
}

void CEnemy::Update()
{
	CheckWall();

	if (m_eMoveDir == MY_DIRECTION::LEFT)
	{
		m_tPosInfo.fX -= m_fMoveSpeed;
	}
	else if (m_eMoveDir == MY_DIRECTION::RIGHT)
	{
		m_tPosInfo.fX += m_fMoveSpeed;
	}

	CObj::UpdateRect();
}

void CEnemy::Render(HDC _hdc)
{
	Rectangle(_hdc,
		m_tRect.left,
		m_tRect.top,
		m_tRect.right,
		m_tRect.bottom);
}

void CEnemy::Release()
{
}

void CEnemy::CheckWall()
{
	if (m_eMoveDir == MY_DIRECTION::LEFT) // 왼쪽으로 가는 도중
	{
		if (m_tPosInfo.fX < m_tPosInfo.fCX * 0.5f)
		{
			m_eMoveDir = MY_DIRECTION::RIGHT;
		}
	}
	else if (m_eMoveDir == MY_DIRECTION::RIGHT)
	{
		if (m_tPosInfo.fX > WINCX - m_tPosInfo.fCX * 0.5f)
		{
			m_eMoveDir = MY_DIRECTION::LEFT;
		}
	}
	
}
