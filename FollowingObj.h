#pragma once
#include "Obj.h"
class CFollowingObj : public CObj
{
public:
	CFollowingObj() : m_vPos{ 600, 600 },
		m_vDir(1, 0), m_vScale(100, 100), m_fAngle(0){}
	~CFollowingObj() {}

public:
	Vector2 Get_vPos()
	{
		return m_vPos;
	}

	void Set_Target(CObj* _pTarget);

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC _dc);
	virtual void Release();

	void UpdateDir();
	void UpdateMove();

	void UpdateDir_asin();
	void UpdateDir_acos();
	void UpdateDir_atan();
private:
	Vector2 m_vPos;
	Vector2 m_vTargetPos;
	Vector2 m_vDir;
	Vector2 m_vScale;
	

	float m_fAngle;
	CObj* pTarget;

};

