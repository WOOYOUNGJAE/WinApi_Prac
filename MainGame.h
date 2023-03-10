#pragma once
#include "Define.h"
#include "Player.h"
#include "Enemy.h"

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

	void DestroyBullet(CObj* _pBullet);
private:
	HDC m_DC;
	CObj* m_pPlayer;
	CObj* m_pEnemy;

	list<CObj*> m_bulletList;

};

