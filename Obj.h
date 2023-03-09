#pragma once
#include "Define.h"

class CObj
{
public:
	CObj() {}
	virtual ~CObj() {}

public:
	//getter

	//setter
	virtual void Set_PosInfo(float delX, float delY) = 0;
	virtual void Set_rc() = 0;

	virtual void Get_Key() = 0;

	virtual void Initialize(HDC _hdc) = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;


protected:
	Pos_Info m_posInfo{};
	RECT m_posRc{};
	HDC m_hdc;

	KEY_INPUT key_input;
	MOVE_DIR move_dir;

	float m_fMoveSpeed;
};

