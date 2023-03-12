#include "stdafx.h"
#include "MainGame.h"
#include "Factory.h"

CMainGame::CMainGame() : m_pPlayer(nullptr)
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
		m_ObjList[OBJ_ID::ID_PLAYER].push_back(Factory<CPlayer>::CreateObj());
		static_cast<CPlayer*>(m_ObjList[OBJ_ID::ID_PLAYER].front())->Set_BulletSlot(&m_ObjList[OBJ_ID::ID_BULLET]);
		m_ObjList[OBJ_ID::ID_PLAYER].push_back(m_pPlayer);
		/*m_pPlayer = new CPlayer;
		m_pPlayer->Initialize();*/
		
		//static_cast<CPlayer*>(m_pPlayer)->Set_BulletSlot(&m_ObjList[OBJ_ID::ID_BULLET]);

	}


}

void CMainGame::Update()
{
	for (size_t i = 0; i < OBJ_ID::OBJ_ID_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end();)
		{
			if (((*iter)->Get_State() & OBJ_STATE::ACTIVE) != 0) // 살아있으면
			{
				(*iter)->Update();
				++iter;
			}
			else
			{
				SAFE_DELETE(*iter);
				iter = m_ObjList[i].erase(iter);
			}
		}
	}

}

void CMainGame::LateUpdate()
{
	for (size_t i = 0; i < OBJ_ID::OBJ_ID_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); ++iter)
		{
			(*iter)->LateUpdate();
		}
	}
}

void CMainGame::Render()
{
	Rectangle(m_dc, 0, 0, WINCX, WINCY);
	Rectangle(m_dc, DESTROYZONE_LEFT, DESTROYZONE_TOP, DESTROYZONE_RIGHT, DESTROYZONE_BOTTOM);

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
