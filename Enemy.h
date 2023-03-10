#pragma once
#include "Obj.h"
class CEnemy : public CObj
{
public:
	CEnemy();
	virtual ~CEnemy();

public:
	//getter

	//setter

	//IURR
	virtual void Initialize();
	virtual void Update();
	virtual void Render(HDC _hdc);
	virtual void Release();

	void CheckWall();
};

