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

	CObj* m_pPlayer;
	list<CObj*> m_bulletList;
};