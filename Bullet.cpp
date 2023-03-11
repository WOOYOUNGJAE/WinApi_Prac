#include "stdafx.h"
#include "Bullet.h"

CBullet::CBullet()
{
}

CBullet::~CBullet()
{
}

void CBullet::Initialize()
{
	m_tPosInfo.fCX = 50.f;
	m_tPosInfo.fCY = 50.f;

	m_fMoveSpeed = 10.f;
}

void CBullet::Update()
{
	switch (m_eMoveDir)
	{
	case MY_MOVEDIRECTION::UP:
		m_tPosInfo.fY -= m_fMoveSpeed;
		break;
	case MY_MOVEDIRECTION::RIGHT:
		m_tPosInfo.fX += m_fMoveSpeed;
		break;
	case MY_MOVEDIRECTION::DOWN:
		m_tPosInfo.fY += m_fMoveSpeed;
		break;
	case MY_MOVEDIRECTION::LEFT:
		m_tPosInfo.fX -= m_fMoveSpeed;
		break;
	case MY_MOVEDIRECTION::RU:
		m_tPosInfo.fY -= m_fMoveSpeed;
		m_tPosInfo.fX += m_fMoveSpeed;
		break;
	case MY_MOVEDIRECTION::LU:
		m_tPosInfo.fX -= m_fMoveSpeed;
		m_tPosInfo.fY -= m_fMoveSpeed;
		break;
	case MY_MOVEDIRECTION::RD:
		m_tPosInfo.fX += m_fMoveSpeed;
		m_tPosInfo.fY += m_fMoveSpeed;
		break;
	case MY_MOVEDIRECTION::LD:
		m_tPosInfo.fX -= m_fMoveSpeed;
		m_tPosInfo.fY += m_fMoveSpeed;
		break;
	default:
		break;
	}

	CObj::RenewRECT();
}

void CBullet::LateUpdate()
{
}

void CBullet::Render(HDC _dc)
{
	Ellipse(_dc, m_rectInfo.left, m_rectInfo.top, m_rectInfo.right, m_rectInfo.bottom);
}

void CBullet::Release()
{
}
