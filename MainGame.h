#pragma once
#include "Define.h"
#include "Player.h"

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
	HDC m_dc;

	list<CObj*> m_ObjList[OBJ_ID::OBJ_ID_END];

	CObj* m_pPlayer;
	//list<CObj*> m_bulletList;
};