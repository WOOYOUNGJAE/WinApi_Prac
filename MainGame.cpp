#include "stdafx.h"
#include "MainGame.h"
#include "Factory.h"
#include "CCollisionManager.h"

CMainGame::CMainGame() : m_tAppInfo {}
{
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_dc = GetDC(g_hwnd);

	if (m_ObjList[OBJ_ID::ID_PLAYER].empty())
	{
		m_ObjList[OBJ_ID::ID_PLAYER].push_back(Factory<CPlayer>::CreateObj());
		static_cast<CPlayer*>(m_ObjList[OBJ_ID::ID_PLAYER].front())->Set_BulletSlot(&m_ObjList[OBJ_ID::ID_BULLET]);

		//InstantiateObj(OBJ_ID::ID_PLAYER);



		//m_ObjList[OBJ_ID::ID_PLAYER].push_back(m_pPlayer);
		/*m_pPlayer = new CPlayer;
		m_pPlayer->Initialize();*/
		
		//static_cast<CPlayer*>(m_pPlayer)->Set_BulletSlot(&m_ObjList[OBJ_ID::ID_BULLET]);

	}

	//InstantiateObj(ID_ENEMY);
	
	m_ObjList[OBJ_ID::ID_ENEMY].push_back(Factory<CEnemy>::CreateObj());
	static_cast<CEnemy*>(m_ObjList[OBJ_ID::ID_ENEMY].front())->Set_BulletSlot(&m_ObjList[OBJ_ID::ID_BULLET]);
	static_cast<CEnemy*>(m_ObjList[OBJ_ID::ID_ENEMY].front())->Set_Player(m_ObjList[OBJ_ID::ID_PLAYER].front());

	m_ObjList[OBJ_ID::ID_MOUSE].push_back(Factory<CMouse>::CreateObj());
	m_ObjList[OBJ_ID::ID_SHIELD].push_back(Factory<CShield>::CreateObj());
	static_cast<CShield*>(m_ObjList[ID_SHIELD].front())->Set_Player(m_ObjList[OBJ_ID::ID_PLAYER].front());

	m_ObjList[ID_ROTATION].push_back(Factory<CRotationObj>::CreateObj());
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

	CCollisionManager::CheckCollision_Sphere(m_ObjList[OBJ_ID::ID_BULLET], m_ObjList[OBJ_ID::ID_ENEMY]);
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

	RenderAppInfo();
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

void CMainGame::RenderAppInfo()
{
	++m_tAppInfo.iFPS;

	if (GetTickCount() > m_tAppInfo.dwTime + 1000)
	{
		// Set String
		swprintf_s(m_tAppInfo.szFPS, L"FPS : %d", m_tAppInfo.iFPS);

		SetWindowText(g_hwnd, m_tAppInfo.szFPS);

		m_tAppInfo.iFPS = 0;
		m_tAppInfo.dwTime = GetTickCount();
	}



}

void CMainGame::InstantiateObj(OBJ_ID _eID)
{
	switch (_eID)
	{
	case OBJ_ID::ID_PLAYER :
		m_ObjList[_eID].push_back(Factory<CPlayer>::CreateObj());
		static_cast<CPlayer*>(m_ObjList[_eID].front())->Set_BulletSlot(&m_ObjList[OBJ_ID::ID_BULLET]);
		break;
	case OBJ_ID::ID_BULLET :
		break;
	case OBJ_ID::ID_ENEMY :
		m_ObjList[_eID].push_back(Factory<CEnemy>::CreateObj());
		static_cast<CEnemy*>(m_ObjList[_eID].front())->Set_BulletSlot(&m_ObjList[OBJ_ID::ID_BULLET]);
		break;
	default:
		break;
	}
}
