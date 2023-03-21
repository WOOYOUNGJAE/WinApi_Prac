#include "stdafx.h"
#include "LineManager2.h"
#include "KeyManager.h"

#define PI 3.141592

CLineManager2* CLineManager2::instance = nullptr;

CLineManager2::CLineManager2()
{
}

CLineManager2::~CLineManager2()
{
}

CLineManager2* CLineManager2::Get_Instance()
{
	if (instance == nullptr)
	{
		instance = new CLineManager2;
	}
	return instance;
}

void CLineManager2::Destroy_Instance()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}

void CLineManager2::Initiate()
{
}

void CLineManager2::Update()
{
	POINT pt{};

	GetCursorPos(&pt);
	ScreenToClient(g_hwnd, &pt);

	if (CKeyManager::Get_Instance()->Key_Down(VK_LBUTTON))
	{
		if (!m_pointArr[(int)TWO_DIR::LEFT].fX &&
			!m_pointArr[(int)TWO_DIR::LEFT].fY)
		{
			m_pointArr[(int)TWO_DIR::LEFT] = LinePoint(pt.x, pt.y);
		}
		else
		{
			m_pointArr[(int)TWO_DIR::RIGHT] = LinePoint(pt.x, pt.y);

			// Make a Line
			m_vecLines.push_back(new CLine2(m_pointArr[(int)TWO_DIR::LEFT], m_pointArr[(int)TWO_DIR::RIGHT]));

			m_pointArr[(int)TWO_DIR::LEFT] = m_pointArr[(int)TWO_DIR::RIGHT];
		}
	}
	else if (CKeyManager::Get_Instance()->Key_Down(VK_RBUTTON)) // 무조건 수평.수직
	{
		if (!m_pointArr[(int)TWO_DIR::LEFT].fX &&
			!m_pointArr[(int)TWO_DIR::LEFT].fY)
		{
			m_pointArr[(int)TWO_DIR::LEFT] = LinePoint(pt.x, pt.y);
		}
		else
		{
			POINT tTmpPoint {};
			if(cosf(PI * 0.25f) )
			{

			}
			m_pointArr[(int)TWO_DIR::RIGHT] = LinePoint(pt.x, pt.y);

			// Make a Line
			m_vecLines.push_back(new CLine2(m_pointArr[(int)TWO_DIR::LEFT], m_pointArr[(int)TWO_DIR::RIGHT]));

			m_pointArr[(int)TWO_DIR::LEFT] = m_pointArr[(int)TWO_DIR::RIGHT];
		}
	}
	else if (CKeyManager::Get_Instance()->Key_Down('0'))
	{
		m_pointArr[(int)TWO_DIR::LEFT] = LinePoint(0, 0);
	}
}

void CLineManager2::Render(HDC _dc)
{
	for (auto& iter : m_vecLines)
	{
		iter->Render(_dc);
	}
}

void CLineManager2::Release()
{
}



