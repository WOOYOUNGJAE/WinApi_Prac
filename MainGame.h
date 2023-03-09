#pragma once
#include "Define.h"
#include "Player.h"

class CMainGame
{
public:
	CMainGame():m_pPlayer(nullptr) {};
	~CMainGame() { Release(); };

public:
	void Initialize();
	void Update();
	void Render();
	void Release();

private:
	HDC m_DC;
	CObj* m_pPlayer;
	list<CObj*> m_bulletList;

};

