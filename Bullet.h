#pragma once
#include "Obj.h"
class CBullet : public CObj
{
public:
	CBullet();
	virtual ~CBullet();

public:
	//getter

	//setter

	//IURR
	virtual void Initialize();
	virtual void Update();
	virtual void Render(HDC _hdc);
	virtual void Release();
};

