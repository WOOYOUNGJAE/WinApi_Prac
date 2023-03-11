#pragma once
#include "Define.h"
class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	// getter

	//setter
	void Set_Pos(float _fX, float _fY)
	{
		m_tPosInfo.fX = _fX;
		m_tPosInfo.fY = _fY;
	}
	void Set_Dir(My_MOVEDIRECTION _eDir)
	{
		m_eMoveDir = _eDir;
	}
	// I U R R
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void LateUpdate() = 0;
	virtual void Render(HDC _dc) = 0;
	virtual void Release() = 0;

	//	
	void RenewRECT();

protected:
	RECT m_rectInfo;
	PosInfo m_tPosInfo;

	My_MOVEDIRECTION m_eMoveDir;
	float m_fMoveSpeed;
};
