#include "stdafx.h"
#include "Player.h"

void CPlayer::Get_Key()
{
	if (GetAsyncKeyState(VK_UP))
	{
		move_dir = MOVE_DIR::UP;
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		move_dir = MOVE_DIR::RIGHT;
	}
	else if (GetAsyncKeyState(VK_LEFT))
	{
		move_dir = MOVE_DIR::LEFT;
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		move_dir = MOVE_DIR::DOWN;
	}
	
}

void CPlayer::Set_PosInfo(float delX, float delY)
{
	m_posInfo.fX += m_fMoveSpeed * delX;
	m_posInfo.fY += m_fMoveSpeed * delY;
}

void CPlayer::Set_rc()
{
	m_posRc.left = m_posInfo.fX - m_posInfo.fHalfWidth;
	m_posRc.top = m_posInfo.fY - m_posInfo.fHalfHeight;
	m_posRc.right = m_posInfo.fX + m_posInfo.fHalfWidth;
	m_posRc.bottom = m_posInfo.fX + m_posInfo.fHalfHeight;
}

void CPlayer::Initialize(HDC _hdc)
{
	m_hdc = _hdc;
	// 포지션 결정
	m_posInfo = { WINCX * 0.5f, WINCY * 0.5f, 20, 20 };

	m_fMoveSpeed = 5;
}

void CPlayer::Update()
{
	// 키 입력
	Get_Key();

	// 입력받은 키 바탕으로 위치 업데이트
	switch (move_dir)
	{
	case UP:
		Set_PosInfo(0.f, 1.f);
		break;
	case RIGHT:
		Set_PosInfo(1.f, 0.f);
		break;
	case DOWN:
		Set_PosInfo(0.f, -1.f);
		break;
	case LEFT:
		Set_PosInfo(-1.f, 0.f);
		break;
	case UR:
		break;
	case UL:
		break;
	case DIR_END:
		break;
	default:
		break;
	}

	Set_rc();
}

void CPlayer::Render()
{
	Rectangle(m_hdc,
		m_posRc.left,
		m_posRc.top,
		m_posRc.right,
		m_posRc.bottom);
}

void CPlayer::Release()
{
}
