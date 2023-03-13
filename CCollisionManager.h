#pragma once
#include "Obj.h"
class CCollisionManager
{
public:
	CCollisionManager();
	~CCollisionManager();
public:
	static void CheckCollision_RECT(list<CObj*> _Dst, list<CObj*> _Src);
	static void CheckCollision_Sphere(list<CObj*> _Dst, list<CObj*> _Src);

	static bool If_InSphereRange(CObj* _Dst, CObj* _Src);

};

