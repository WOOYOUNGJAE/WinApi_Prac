#include "stdafx.h"
#include "FollowingObj.h"
#include "DebugLog.h"
#include "Mario.h"
#define PI 3.141592

void CFollowingObj::Set_Target(CObj* _pTarget)
{
	/*m_vTargetPos =
		Vector2(_pTarget->Get_PosInfo().fX,
			_pTarget->Get_PosInfo().fY
		);*/
	pTarget = _pTarget;
}

void CFollowingObj::Initialize()
{
	m_fMoveSpeed = 2.f;
}

void CFollowingObj::Update()
{
	m_vTargetPos = static_cast<CMario2*>(pTarget)->Get_vPos();

	UpdateDir();

	UpdateMove();

	CObj::RenewRECT();
}

void CFollowingObj::LateUpdate()
{
}

void CFollowingObj::Render(HDC _dc)
{
	Rectangle(
		_dc,
		m_vPos.fX - 30,
		m_vPos.fY - 30,
		m_vPos.fX + 30,
		m_vPos.fY + 30
	);

	DebugLog::Print0( _dc, DebugLog::Combine_Str(L"angle: ",  m_fAngle));
}

void CFollowingObj::Release()
{
}

void CFollowingObj::UpdateDir()
{
	UpdateDir_asin();
	//UpdateDir_acos();
	//UpdateDir_atan();

	m_vDir.Normalize();
}

void CFollowingObj::UpdateMove()
{
	m_vPos.fX += m_vDir.fX * m_fMoveSpeed;
	m_vPos.fY -= m_vDir.fY * m_fMoveSpeed;
}

void CFollowingObj::UpdateDir_asin()
{
	float fWidth = m_vTargetPos.fX - m_vPos.fX;
	float fHeight = m_vTargetPos.fY - m_vPos.fY;
	float fRadius = sqrtf(fWidth * fWidth + fHeight * fHeight);

	//m_fAngle = asinf(fHeight / fRadius); // -90 90
	//
	//if (m_vTargetPos.fX < m_vPos.fX)
	//{
	//	m_fAngle = PI - m_fAngle;
	//}

	m_fAngle = acosf(fWidth / fRadius);
	if (m_vTargetPos.fY > m_vPos.fY)
	{
		m_fAngle *= -1.f;
	}




	m_vDir.fX = cosf(m_fAngle);
	m_vDir.fY = sinf(m_fAngle);
}

void CFollowingObj::UpdateDir_acos()
{
}

void CFollowingObj::UpdateDir_atan()
{
}
