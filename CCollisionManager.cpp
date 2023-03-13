#include "stdafx.h"
#include "CCollisionManager.h"

CCollisionManager::CCollisionManager()
{
}

CCollisionManager::~CCollisionManager()
{
}

void CCollisionManager::CheckCollision_RECT(list<CObj*> _Dst, list<CObj*> _Src)
{
	RECT tmpRC{};

	for (auto& iter0 : _Dst)
	{
		for (auto& iter1 : _Src)
		{
			if ( IntersectRect(&tmpRC, &((iter0)->Get_Rect()), &((iter1)->Get_Rect())) )
			{
				iter1->Set_State(false, OBJ_STATE::ACTIVE);
				iter0->Set_State(false, OBJ_STATE::ACTIVE);
			}
		}
	}
}

void CCollisionManager::CheckCollision_Sphere(list<CObj*> _Dst, list<CObj*> _Src)
{
	for (auto& iter0 : _Dst)
	{
		for (auto& iter1 : _Src)
		{
			if (If_InSphereRange(iter0, iter1))
			{
				iter1->Set_State(false, OBJ_STATE::ACTIVE);
				iter0->Set_State(false, OBJ_STATE::ACTIVE);
			}
		}
	}
}

bool CCollisionManager::If_InSphereRange(CObj* _Dst, CObj* _Src)
{
	float fWidth =  abs(_Dst->Get_PosInfo().fX - _Src->Get_PosInfo().fX);
	float fHeight=  abs(_Dst->Get_PosInfo().fY - _Src->Get_PosInfo().fY);
	float fDistance = sqrt(fWidth * fWidth + fHeight * fHeight);

	float fRadius = (_Dst->Get_PosInfo().fCX + _Src->Get_PosInfo().fCY) * 0.5f;

	return fRadius >= fDistance;
}
