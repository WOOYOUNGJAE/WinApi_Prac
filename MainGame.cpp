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

	if (!m_pEnemy)
	{
		m_pEnemy = new CEnemy;
		static_cast<CEnemy*>(m_pEnemy)->Initialize();
	}
}

void CMainGame::Update()
{
	m_pPlayer->Update();
	m_pEnemy->Update();
	for (auto& iter : m_bulletList)
	{
		iter->Update();
	}
}

void CMainGame::Render()
{
	Rectangle(m_DC, 0, 0, WINCX, WINCY);

	m_pPlayer->Render(m_DC);
	m_pEnemy->Render(m_DC);
	for (auto& iter : m_bulletList)
	{
		if (iter)
			iter->Render(m_DC);
	}
}

void CMainGame::Release()
{
}

void CMainGame::DestroyBullet(CObj* _pBullet)
{
	m_bulletList;
	list<CObj*>::iterator iter = m_bulletList.begin();
	iter = find(m_bulletList.begin(), m_bulletList.end(), _pBullet);


	Safe_Delete(*iter);
	m_bulletList.erase(iter);
}
