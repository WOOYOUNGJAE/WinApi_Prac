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
		static_cast<CPlayer*>(m_pPlayer)->Set_BulletSlot(&m_ObjList[OBJ_ID::ID_BULLET]);

		m_ObjList[OBJ_ID::ID_PLAYER].push_back(m_pPlayer);
	}
}

void CMainGame::Update()
{
	for (size_t i = 0; i < OBJ_ID::OBJ_ID_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); ++iter)
		{
			(*iter)->Update();
		}
	}

}

void CMainGame::LateUpdate()
{
	m_pPlayer->LateUpdate();
}

void CMainGame::Render()
{
	Rectangle(m_dc, 0, 0, WINCX, WINCY);

	for (size_t i = 0; i < OBJ_ID::OBJ_ID_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); ++iter)
		{
			(*iter)->Render(m_dc);
		}
	}
}

void CMainGame::Release()
{
	for (size_t i = 0; i < OBJ_ID::OBJ_ID_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); ++iter)
		{
			SAFE_DELETE(*iter);
		}
	}
}
