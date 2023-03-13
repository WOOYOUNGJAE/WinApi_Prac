#pragma once
#include "Obj.h"
class CMouse : public CObj
{
public:
	CMouse();
	~CMouse();
public:
	// getter

	//setter

	// I U R R
	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC _dc) override;
	virtual void Release();

};

