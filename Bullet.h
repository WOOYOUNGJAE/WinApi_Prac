#pragma once
#include "Obj.h"

class CMainGame;
class CBullet : public CObj
{
public:
	CBullet();
	virtual ~CBullet();

public:
	//getter

	//setter
	void Set_pMainGame(CMainGame* _pMainGame) { m_pMainGame = _pMainGame; }

	//IURR
	virtual void Initialize();
	virtual void Update();
	virtual void Render(HDC _hdc);
	virtual void Release();

	void CheckCeiling();
	void SelfDestroy();
private:
	CMainGame* m_pMainGame;
};

