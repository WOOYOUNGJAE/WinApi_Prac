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
		// �־�� �� ��ġ vs �� �÷��̾� ��ġ
		float fCurrentY = iter->ReturnY(static_cast<CMario*>(pPlayer)->Get_vPos().fX);
		if (// �÷��̾ �־�� �� ��ġ ���Ͽ� ������
			//static_cast<CMario*>(pPlayer)->Get_feetY() >= 	fCurrentY )
			static_cast<CMario*>(pPlayer)->Get_vPos().fY + 50 >= fCurrentY )
		{
			static_cast<CMario*>(pPlayer)->Set_OnGround(true);
			static_cast<CMario*>(pPlayer)->Set_YPos(fCurrentY); // ���� ����
			static_cast<CMario*>(pPlayer)->ResetGround();
		}
		else // �� ���� ������
		{
 			static_cast<CMario*>(pPlayer)->Set_OnGround(false); // �߷� ����
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
