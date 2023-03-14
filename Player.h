#pragma once
#include "Obj.h"
#include "Define.h"

class CPlayer : public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	// getter

	//setter
	void Set_BulletSlot(list<CObj*>* _pBulletSlot);

	// I U R R
	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC _dc);
	virtual void Release();

	//
	CObj* CreateBullet(MY_MOVEDIRECTION _eDir);
	void GetKey();

private: // methods
	void MoveForward();
	void Rotate();
private:
	list<CObj*>* m_pBulletSlot;

	//rotate info
	float fDeltaX;
	float fDeltaY;
	float fDegree;
};