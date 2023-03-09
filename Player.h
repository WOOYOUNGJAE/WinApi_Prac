#pragma once
#include "Obj.h"

class CPlayer : public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	//getter

	//setter

	//IURR
	virtual void Initialize();
	void Initialize(list<CObj*>* _pBullet);
	virtual void Update();
	virtual void Render(HDC _hdc);
	virtual void Release();

private:
	void EnterKey();
	CObj* CreateBullet(MY_DIRECTION _eDir);
private:
	list<CObj*>* m_pBullet;
};

