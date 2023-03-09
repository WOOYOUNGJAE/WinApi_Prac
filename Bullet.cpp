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
	m_tPosInfo.fCX = 20.f;
	m_tPosInfo.fCY = 20.f;

	m_fMoveSpeed = 10.f;
}

void CBullet::Update()
{
	switch (m_eMoveDir)
	{
	case MY_DIRECTION::LEFT:
		m_tPosInfo.fX -= m_fMoveSpeed;
		break;
	case MY_DIRECTION::UP:
		m_tPosInfo.fY -= m_fMoveSpeed;
		break;
	case MY_DIRECTION::RIGHT:
		m_tPosInfo.fX += m_fMoveSpeed;
		break;
	case MY_DIRECTION::DOWN:
		m_tPosInfo.fY += m_fMoveSpeed;
		break;
	case MY_DIRECTION::LU:
		m_tPosInfo.fX -= m_fMoveSpeed;
		m_tPosInfo.fY -= m_fMoveSpeed;
		break;
	case MY_DIRECTION::RU:
		m_tPosInfo.fX += m_fMoveSpeed;
		m_tPosInfo.fY -= m_fMoveSpeed;
		break;
	case MY_DIRECTION::LD:
		m_tPosInfo.fX -= m_fMoveSpeed;
		m_tPosInfo.fY += m_fMoveSpeed;
		break;
	case MY_DIRECTION::RD:
		m_tPosInfo.fX += m_fMoveSpeed;
		m_tPosInfo.fY += m_fMoveSpeed;
		break;
	case MY_DIRECTION::END:
		break;
	default:
		break;
	}

	CObj::UpdateRect();
}

void CBullet::Render(HDC _hdc)
{
	Ellipse(_hdc,
		m_tRect.left,
		m_tRect.top,
		m_tRect.right,
		m_tRect.bottom);
}

void CBullet::Release()
{
}
