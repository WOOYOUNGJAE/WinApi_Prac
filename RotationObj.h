#pragma once
#include "Obj.h"

class CRotationObj : public CObj
{
public:
	CRotationObj();
	virtual ~CRotationObj();;

public:

	virtual void Initialize() override;
	virtual void Update() override;
	void LateUpdate() override {};
	virtual void Render(HDC _dc) override;
	void Release() override {};
	

	void UpdateMove();

	void EnterKey_MoveOnly();
	void EnterKey_MoveAndRotate();
private:
	Vector2 m_vPos;
	Vector2 m_vDir;
	Vector2 m_vScale;

	float m_fAngle;
};

