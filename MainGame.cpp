#include "stdafx.h"
#include "MainGame.h"

void CMainGame::Initialize(HDC _hdc)
{
	pPlayer = new CPlayer;
	dynamic_cast<CPlayer*>(pPlayer)->Initialize(_hdc);
}

void CMainGame::Update()
{

}

void CMainGame::Release()
{
	Safe_Delete(pPlayer);
}
