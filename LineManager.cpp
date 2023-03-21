#include "stdafx.h"
#include "LineManager.h"
#include "Mario.h"

CLineManager* CLineManager::pLineMgr = nullptr;

CLineManager::CLineManager()
{
}

CLineManager::~CLineManager()
{
}

void CLineManager::Initiate()
{
	if (pLineMgr == nullptr)
	{
		pLineMgr = new CLineManager;
	}
}

void CLineManager::Update()
{
}

void CLineManager::LateUpdate()
{
}

void CLineManager::Render(HDC _dc)
{
	for(auto& iter : lineList)
	{
		iter->Render(_dc);
	}
}

void CLineManager::Release()
{
}

void CLineManager::CheckPlayerOnGround()
{
	for (auto& iter : lineList)
	{
		// 있어야 할 위치 vs 현 플레이어 위치
		float fCurrentY = iter->ReturnY(static_cast<CMario*>(pPlayer)->Get_vPos().fX);
		if (// 플레이어가 있어야 할 위치 이하에 있으면
			//static_cast<CMario*>(pPlayer)->Get_feetY() >= 	fCurrentY )
			static_cast<CMario*>(pPlayer)->Get_vPos().fY + 50 >= fCurrentY )
		{
			static_cast<CMario*>(pPlayer)->Set_OnGround(true);
			static_cast<CMario*>(pPlayer)->Set_YPos(fCurrentY); // 라인 따라
			static_cast<CMario*>(pPlayer)->ResetGround();
		}
		else // 땅 위에 있으면
		{
 			static_cast<CMario*>(pPlayer)->Set_OnGround(false); // 중력 적용
		}
	}
}


class my_class
{
public:
	static my_class* Get_Instance()
	{
		if (instance == nullptr)
		{
			instance = new my_class;
		}
		return instance;
	}

private:
	static my_class* instance;
};

my_class* my_class::instance = nullptr;
