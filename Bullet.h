#pragma once
#include "Obj.h"
#include "Define.h"

class CBullet : public CObj
{
public:
	CBullet();
	virtual ~CBullet();

public:
	// getter

	//setter

	// I U R R
	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC _dc);
	virtual void Release();
	
};