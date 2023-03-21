#include "stdafx.h"
#include "Mario.h"
#include "DebugLog.h"


CMario::CMario() : m_vPos{ 400, 300 },
m_vDir(0, 0), m_vScale(100,100), m_fAngle(0),
m_fRotSpeed(5.f), m_bIsGround(false), m_fCurrentTime(0), m_fJumpAngle(0),
m_fJumpPower(15), m_fY_Velocity(0)
{
	m_fMoveSpeed = 7.f;
}

CMario::~CMario()
{}

void CMario::Initialize()
{
	m_vDir.fX = 0;
	m_vDir.fY = 0;

	fFeetY = m_vPos.fY + 0.5f * m_vScale.fY;
}

void CMario::Update()
{
	EnterKey_Mario();
	UpdateInAir();

	//UpdateMove();

	//EnterKey_MoveOnly();


	//EnterKey_MoveAndRotate();

	CObj::RenewRECT();
}

void CMario::Render(HDC _dc)
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

	/*DebugLog::Print0(_dc, DebugLog::Combine_Str(L"Angle: ", m_fAngle));
	DebugLog::Print1(_dc, DebugLog::Combine_Str(L"Angle: ", m_vDir.fX));
	DebugLog::Print2(_dc, DebugLog::Combine_Str(L"Angle: ", m_vDir.fY));*/
}

void CMario::UpdateMove()
{
	if (m_bIsGround == false)
	{
		m_vPos.fX += m_vDir.fX * m_fMoveSpeed;
		return;
	}
 	m_vPos.fX += m_vDir.fX * m_fMoveSpeed; 
	m_vPos.fY -= m_vDir.fY * m_fMoveSpeed;

}
 
void CMario::UpdateInAir()
{
	if (m_bIsGround)
		return;

	m_fCurrentTime += 1.f;

	float fDeltaX = m_vDir.fX * cosf(m_fJumpAngle) * m_fCurrentTime;
	float fDeltaY = m_vDir.fY * sinf(m_fJumpAngle) * m_fCurrentTime -
		0.5f * GRAVITY * m_fCurrentTime * m_fCurrentTime;
	
 	m_vPos.fX += fDeltaX;
	m_vPos.fY -= fDeltaY;
	
	UpdateMove();
}
 
void CMario::EnterKey_MoveOnly()
{

	if (GetAsyncKeyState(VK_UP))
	{
		m_vDir = Vector2(0.f, -1.f);

		if (GetAsyncKeyState(VK_LEFT))
		{
			m_vDir = m_vDir + Vector2(-1.f, 0.f);
			m_vDir.Normalize();
			UpdateMove();
			return;
		}
		else if (GetAsyncKeyState(VK_RIGHT))
		{
			m_vDir = m_vDir + Vector2(1.f, 0.f);
			m_vDir.Normalize();
			UpdateMove();
			return;
		}
		UpdateMove();
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		m_vDir = Vector2(0.f, +1.f);
		
		if (GetAsyncKeyState(VK_LEFT))
		{
			m_vDir = m_vDir + Vector2(-1.f, 0.f);
			m_vDir.Normalize();
			UpdateMove();
			return;
		}
		else if (GetAsyncKeyState(VK_RIGHT))
		{
			m_vDir = m_vDir + Vector2(1.f, 0.f);
			m_vDir.Normalize();
			UpdateMove();
			return;
		}
		UpdateMove();
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		m_vDir =  Vector2(1.f, 0.f);
		UpdateMove();
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		m_vDir =  Vector2(-1.f, 0.f);
		UpdateMove();
	}


}

void CMario::EnterKey_MoveAndRotate()
{

	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_fAngle += m_fRotSpeed;
		float m_fDegreeToRad = m_fAngle * (PI / 180.f);
		m_vDir = Vector2(cosf(m_fDegreeToRad), sinf(m_fDegreeToRad));
		m_vDir.Normalize();

	}
	else if (GetAsyncKeyState(VK_LEFT))
	{
		m_fAngle -= m_fRotSpeed;
		float m_fDegreeToRad = m_fAngle * (PI / 180.f);
		m_vDir = Vector2(cosf(m_fDegreeToRad), sinf(m_fDegreeToRad));
		m_vDir.Normalize();
	}



	if (GetAsyncKeyState(VK_UP) || (GetAsyncKeyState(VK_DOWN)))
	{
		UpdateMove();
	}	
}

void CMario::EnterKey_Mario()
{

	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_vDir = Vector2(1.f, 0.f);
		m_vDir.Normalize();
		UpdateMove();
		//return;
	}
	else if (GetAsyncKeyState(VK_LEFT))
	{
		m_vDir = Vector2(-1.f, 0.f);
		m_vDir.Normalize();
		UpdateMove();
		//return;
	}

#pragma region Æ÷¹°¼±
	if (GetAsyncKeyState(VK_SPACE)) 
	{
		if (m_bIsGround == false)
			return;

  		m_bIsGround = false;
		m_fCurrentTime = 0;

		if (m_fJumpAngle == 0)
		{ 
			m_fJumpAngle = PI * 0.5f;
			m_vDir = Vector2(0, m_fJumpPower);
			return; 
		}
		 
		Vector2 vNewDir = m_vDir + Vector2(0, -1);
		/*Functions::Inner_Product(m_vDir, vNewDir)
			== abs(m_vDir.magnitude) * abs(vNewDir.magnitude) * cosf(m_fJumpAngle);
		cosf(m_fJumpAngle) == Functions::Inner_Product(m_vDir, vNewDir) /
			abs(m_vDir.magnitude * vNewDir.magnitude);*/



		/*m_fJumpAngle = acosf(Functions::Inner_Product(m_vDir, vNewDir) /
			abs(m_vDir.magnitude * vNewDir.magnitude));*/
		m_fJumpAngle = atan2f(m_fJumpPower, m_vDir.fX);
	}      
#pragma  endregion
	
}

void CMario::ResetGround()
{
	m_fCurrentTime = 0.f;
	m_vDir = Vector2(0, 0);
	m_fJumpAngle = 0.f;
}	 