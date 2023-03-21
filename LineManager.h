#pragma once
#include "Line.h"
#include "Obj.h"
class CLineManager
{
public:
	CLineManager();
	~CLineManager();

public:
	static CLineManager* Get_Instance()
	{
		if (pLineMgr == nullptr)
		{
			pLineMgr = new CLineManager;
		}
		return pLineMgr;
	}

	void Set_Player(CObj* _pPlayer) { pPlayer = _pPlayer; }

	void Initiate();
	void Update();
	void LateUpdate();
	void Render(HDC _dc);
	void Release();

	void AddLine(CLine* _pLine)
	{
		lineList.push_back(_pLine);
	}

	void CheckPlayerOnGround();

private:
	static CLineManager* pLineMgr;
	list<CLine*> lineList;

	CObj* pPlayer;
};

