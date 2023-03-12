#include "stdafx.h"
#include "Enemy.h"
#include  "Bullet.h"

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

void CEnemy::Initialize()
{
	m_tPosInfo = { WINCX * 0.5f , DESTROYZONE_TOP + 50.f , 50, 20 };

	m_eMoveDir = MY_MOVEDIRECTION::RIGHT;
	m_fMoveSpeed = 8.f;
}

void CEnemy::Update()
{
	for (auto iter = m_pBullet_FromPlayer->begin(); iter != m_pBullet_FromPlayer->end(); ++iter)
	{
		CheckCollision((*iter));
	}

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
