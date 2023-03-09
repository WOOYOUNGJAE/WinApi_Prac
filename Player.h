#pragma once
#include "Obj.h"
class CPlayer : public CObj
{
public:
	CPlayer() {}
	~CPlayer() {}
public:
	//getter
	virtual void Get_Key();

	//setter
	virtual void Set_PosInfo(float delX, float delY);
	virtual void Set_rc();

	virtual void Initialize(HDC _hdc);
	virtual void Update();
	virtual void Render();
	virtual void Release();
};

