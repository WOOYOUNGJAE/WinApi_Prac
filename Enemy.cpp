#include "stdafx.h"
#include "Enemy.h"
#include  "Bullet.h"

#define PI 3.141592f
CEnemy::CEnemy() 
{
}

CEnemy::~CEnemy()
{
	Release();
}

void CEnemy::Set_BulletSlot(list<CObj*>* _pBulletSlot)
{
	m_pBullet_FromPlayer = _pBulletSlot;
}

void CEnemy::Set_Player(CObj* _pPlayer)
{
	m_pPlayer = _pPlayer;
}

void CEnemy::Initialize()
{
	m_tPosInfo = { WINCX * 0.5f , DESTROYZONE_TOP + 50.f , 50, 20 };

	m_eMoveDir = MY_MOVEDIRECTION::RIGHT;
	m_fMoveSpeed = 8.f;
}

void CEnemy::Update()
{
	/*for (auto iter = m_pBullet_FromPlayer->begin(); iter != m_pBullet_FromPlayer->end(); ++iter)
	{
		CheckCollision((*iter));
	}*/

	//CheckWall();

	/*if (m_eMoveDir == MY_MOVEDIRECTION::LEFT)
	{
		m_tPosInfo.fX -= m_fMoveSpeed;
	}
	else if (m_eMoveDir == MY_MOVEDIRECTION::RIGHT)
	{
		m_tPosInfo.fX += m_fMoveSpeed;
	}*/

	TargetPlayer(); // angle 업데이트

	m_fTargetX = (m_tPosInfo.fX + cosf(m_fAngle));
	m_fTargetY = (m_tPosInfo.fY + sinf(m_fAngle));

	m_tPosInfo.fX = m_fTargetX;
	m_tPosInfo.fY = m_fTargetY;

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

	/*MoveToEx(_dc, m_tPosInfo.fX, m_tPosInfo.fY, nullptr);
	LineTo(_dc, targetPoint.x * 100.f, targetPoint.y * 100.f);*/
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

void CEnemy::CheckCollision(CObj* _pObjType)
{
	RECT* pOtherRC = &_pObjType->Get_Rect();
	RECT rcColArea{};
	if ( IntersectRect(&rcColArea, &m_rectInfo, pOtherRC) )
	{
		if (dynamic_cast<CBullet*>(_pObjType))
		{
			static_cast<CBullet*>(_pObjType)->Set_State(false, OBJ_STATE::ACTIVE);
			m_eState &= ~OBJ_STATE::ACTIVE;
		}
	}
}

void CEnemy::TargetPlayer()
{
	float fWidth = (m_pPlayer->Get_PosInfo().fX - m_tPosInfo.fX);
	float fHeight = (m_pPlayer->Get_PosInfo().fY - m_tPosInfo.fY); 

	//m_fDistanceToPlayer = sqrt(fWidth * fWidth + fHeight * fHeight);


	float rate = fHeight / fWidth;

	//m_fAngle = atan2(fHeight, fWidth);

	m_fAngle = atanf(rate);

	if (m_fAngle > PI * 0.5f)
	{
		m_fAngle -= PI;
	}
	else if (m_fAngle < -PI * 0.5f)
	{
		m_fAngle += PI;
	}	
}
