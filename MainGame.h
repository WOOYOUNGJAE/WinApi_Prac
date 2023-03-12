#pragma once
#include "Define.h"
#include "AllObjHeaders.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	// getter

	//setter

	// I U R R
	void Initialize();
	void Update();
	void LateUpdate();
	void Render();
	void Release();

private:
	void RenderAppInfo();
	void InstantiateObj(OBJ_ID _eID);
private:
	HDC m_dc;
	AppStateInfo m_tAppInfo;


	list<CObj*> m_ObjList[OBJ_ID::OBJ_ID_END];
	//list<CObj*> m_bulletList;
};