#include "stdafx.h"
#include "RotationObj.h"

CRotationObj::CRotationObj() : m_vPos{ 400, 300 },
m_vDir(1, 1), m_vScale(100,100), m_fAngle(0)
{
	m_fMoveSpeed = 7.f;
}

CRotationObj::~CRotationObj()
{}

void CRotationObj::Initialize()
{

}

void CRotationObj::Update()
{
	EnterKey_MoveOnly();

	//UpdateMove();


	CObj::RenewRECT();
}

void CRotationObj::Render(HDC _dc)
{
	Rectangle(
		_dc,
		m_vPos.fX - 50,
		m_vPos.fY - 50,
		m_vPos.fX + 50,
		m_vPos.fY + 50
	);

	//Posin
	MoveToEx(_dc, m_vPos.fX, m_vPos.fY, nullptr);
	LineTo(_dc, m_vPos.fX + m_vDir.fX * 80.f, m_vPos.fY + m_vDir.fY * 80.f);
}

void CRotationObj::UpdateMove()
{
	m_vPos.fX += m_vDir.fX * m_fMoveSpeed;
	m_vPos.fY += m_vDir.fY * m_fMoveSpeed;

}

void CRotationObj::EnterKey_MoveOnly()
{

	//if (GetAsyncKeyState(VK_UP))
	//{
	//	m_vDir = Vector2(0.f, -1.f);

	//	if (GetAsyncKeyState(VK_LEFT))
	//	{
	//		m_vDir = m_vDir + Vector2(-1.f, 0.f);
	//		m_vDir.Normalize();
	//		UpdateMove();
	//		return;
	//	}
	//	else if (GetAsyncKeyState(VK_RIGHT))
	//	{
	//		m_vDir = m_vDir + Vector2(1.f, 0.f);
	//		m_vDir.Normalize();
	//		UpdateMove();
	//		return;
	//	}
	//	UpdateMove();
	//}
	//else if (GetAsyncKeyState(VK_DOWN))
	//{
	//	m_vDir = Vector2(0.f, +1.f);
	//	
	//	if (GetAsyncKeyState(VK_LEFT))
	//	{
	//		m_vDir = m_vDir + Vector2(-1.f, 0.f);
	//		m_vDir.Normalize();
	//		UpdateMove();
	//		return;
	//	}
	//	else if (GetAsyncKeyState(VK_RIGHT))
	//	{
	//		m_vDir = m_vDir + Vector2(1.f, 0.f);
	//		m_vDir.Normalize();
	//		UpdateMove();
	//		return;
	//	}
	//	UpdateMove();
	//}
	//else if (GetAsyncKeyState(VK_RIGHT))
	//{
	//	m_vDir =  Vector2(1.f, 0.f);
	//	UpdateMove();
	//}
	//if (GetAsyncKeyState(VK_LEFT))
	//{
	//	m_vDir =  Vector2(-1.f, 0.f);
	//	UpdateMove();
	//}


}

void CRotationObj::EnterKey_MoveAndRotate()
{

	if (GetAsyncKeyState(VK_RIGHT))
	{
		
	}
	else if (GetAsyncKeyState(VK_LEFT))
	{
		
	}



	if (GetAsyncKeyState(VK_UP) || (GetAsyncKeyState(VK_DOWN)))
	{
		UpdateMove();
	}

	
}	