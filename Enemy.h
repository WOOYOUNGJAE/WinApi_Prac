#pragma once
#include  "Obj.h"
class CEnemy : CObj
{
public:
	CEnemy();
	virtual ~CEnemy() override;

public:
	// getter

	//setter

	// I U R R
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC _dc) override;
	virtual void Release() override;

	void CheckWall();
};
