#pragma once
#include "Define.h"
class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	// getter
	int Get_State();
	RECT& Get_Rect();

	//setter
	void Set_Pos(float _fX, float _fY)
	{
		m_tPosInfo.fX = _fX;
		m_tPosInfo.fY = _fY;
	}
	void Set_Dir(MY_MOVEDIRECTION _eDir)
	{
		m_eMoveDir = _eDir;
	}
	void Set_State(bool _bOn, OBJ_STATE _eState)
	{
		if (_bOn)
		{
			m_eState |= _eState;
		}
		else
		{
			m_eState &= ~_eState;			
		}
	}
	
	// I U R R
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void LateUpdate() = 0;
	virtual void Render(HDC _dc) = 0;
	virtual void Release() = 0;

	//	
	virtual void RenewRECT();
	virtual void CheckCollision(CObj* _pObjType);
protected:
	int m_eState;
	int m_eObjID;
	RECT m_rectInfo;
	PosInfo m_tPosInfo;


	// ¿òÁ÷ÀÓ
	MY_MOVEDIRECTION m_eMoveDir;
	float m_fMoveSpeed;
};