#pragma once
#include "Obj.h"
class CPlayer : public CObj
{
public:
	CPlayer();
	~CPlayer();

public:
	// getter

	//setter
	// 
	// I U R R
	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC _dc);
	virtual void Release();

	void GetKey();
};