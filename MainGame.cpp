#include "stdafx.h"
#include "MainGame.h"

void CMainGame::Initialize()
{
	m_DC = GetDC(g_hwnd);

	if (!m_pPlayer)
	{
		m_pPlayer = new CPlayer;
		static_cast<CPlayer*>(m_pPlayer)->Initialize(&m_bulletList);
	}
}

void CMainGame::Update()
{
	m_pPlayer->Update();
	for (auto& iter : m_bulletList)
	{
		iter->Update();
	}
}

void CMainGame::Render()
{
	Rectangle(m_DC, 0, 0, WINCX, WINCY);

	m_pPlayer->Render(m_DC);
	for (auto& iter : m_bulletList)
	{
		iter->Render(m_DC);
	}
}

void CMainGame::Release()
{
}
