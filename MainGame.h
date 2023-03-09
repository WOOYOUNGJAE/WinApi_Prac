#pragma once
#include "Obj.h"
#include "Player.h"
class CMainGame
{
public:
	CMainGame(): pPlayer(nullptr)
	{}
	~CMainGame() { Release(); }

public:
	void Initialize(HDC _hdc);
	void Update();
	void Release();

private:
	CObj* pPlayer;
};

