#pragma once

#include "Define.h"
class CObj
{
public:
	CObj(): m_eMoveDir(MY_DIRECTION::END), m_fMoveSpeed(0.f)
	{
		ZeroMemory(&m_tPosInfo, sizeof(PosInfo));
		ZeroMemory(&m_tRect, sizeof(RECT));
	}
	virtual ~CObj() {}

public:
	//getter

	//setter
	void Set_Dir(MY_DIRECTION _eDir) { m_eMoveDir = _eDir; }
	void Set_Pos(float _fX, float _fY) 
	{
		m_tPosInfo.fX = _fX;
		m_tPosInfo.fY = _fY;
	}

	//IURR
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render(HDC _hdc) = 0;
	virtual void Release() = 0;

	//Functions
	void UpdateRect(); // 공식같은거라 오버라이딩 없음
protected:
	PosInfo m_tPosInfo;
	RECT m_tRect;
	MY_DIRECTION m_eMoveDir;
	float m_fMoveSpeed;
};

