#pragma once
#include "Obj.h"
class CShield : public CObj
{
public:
	CShield();
	virtual ~CShield() override;

public:
	// getter

	//setter
	void Set_Player(CObj* _pPlayer);

	// I U R R
	virtual void Initialize() override;
	virtual void Initialize(CObj* _pPlayer);
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC _dc) override;
	virtual void Release() override;

	void UpdatePos();
private:
	CObj* m_pPlayer;
	float m_fAngle;
	float m_fDelta;
	float m_fRotSpeed;
};

