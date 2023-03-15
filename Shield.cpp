#include "stdafx.h"
#include "Shield.h"

CShield::CShield() : m_fDelta(0), m_fRotSpeed(10)
{
}

CShield::~CShield()
{
}

void CShield::Set_Player(CObj* _pPlayer)
{
	m_pPlayer = _pPlayer;
}

void CShield::Initialize()
{
	m_tPosInfo = { 0.f, 0.f, 40, 40 };
	m_fMoveSpeed = 5.f;
}

void CShield::Initialize(CObj* _pPlayer)
{

}

void CShield::Update()
{
	UpdatePos();

	CObj::RenewRECT();
}

void CShield::LateUpdate()
{
}

void CShield::Render(HDC _dc)
{
	Ellipse(_dc,
		m_rectInfo.left,
		m_rectInfo.top,
		m_rectInfo.right,
		m_rectInfo.bottom);
}
void CShield::Release()
{
}

void CShield::UpdatePos()
{
	++m_fDelta;
	float fTmpX = m_pPlayer->Get_PosInfo().fX;
	float fTmpY = m_pPlayer->Get_PosInfo().fY;


	m_tPosInfo.fX = fTmpX  + cosf(m_fDelta * m_fRotSpeed * (1 / 180.f)) * m_fMoveSpeed * 30;
	m_tPosInfo.fY = fTmpY  - sinf(m_fDelta * m_fRotSpeed * (1 / 180.f)) * m_fMoveSpeed * 30;
}
