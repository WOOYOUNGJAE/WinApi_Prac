#pragma once
#include "Obj.h"

#define PI 3.141592
//#define GRAVITY 9.81
#define GRAVITY 3

class CMario2 : public CObj
{
public:
	CMario2();
	virtual ~CMario2();

public:
	Vector2 Get_vPos() { return m_vPos; }
	float Get_feetY() { return fFeetY; }
	bool Get_IFOnGround() { return m_bIsGround; }
	void Set_OnGround(bool _b) { m_bIsGround = _b; }
	void Set_YPos(float _y) { m_vPos.fY = _y - m_vScale.fY * 0.5f; }

	virtual void Initialize() override;
	virtual void Update() override;
	void LateUpdate() override {};
	virtual void Render(HDC _dc) override;
	void Release() override {};


	void UpdateMove();
	void UpdateInAir();

	void EnterKey_MoveOnly();
	void EnterKey_MoveAndRotate();
	void EnterKey_Mario();

	void ResetGround();
private:
	Vector2 m_vPos;
	Vector2 m_vDir;
	Vector2 m_vScale;

	bool m_bIsGround;
	bool m_bIsJumping;
	float fFeetY;

	float m_fCurrentTime;
	float m_fJumpAngle;
	float m_fJumpPower;

	float m_fAngle;
	float m_fRotSpeed;


	float m_fY_Velocity;
};

