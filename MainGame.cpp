#include "stdafx.h"
#include "MainGame.h"

CMainGame::CMainGame()
{
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_dc = GetDC(g_hwnd);

	if (m_pPlayer == nullptr)
	{
		m_pPlayer = new CPlayer;
		m_pPlayer->Initialize();
	}
}

void CMainGame::Update()
{
	m_pPlayer->Update();
}

void CMainGame::LateUpdate()
{
	m_pPlayer->LateUpdate();
}

void CMainGame::Render()
{
	Rectangle(m_dc, 0, 0, WINCX, WINCY);

	static_cast<CPlayer*>(m_pPlayer)->Render(m_dc);
}

void CMainGame::Release()
{
}
