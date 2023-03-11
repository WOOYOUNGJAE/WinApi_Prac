#pragma once
#include "Obj.h"
#include "Define.h"
template <typename T>
class Factory
{
public:
	Factory();
	~Factory();

public:
	static CObj* CreateObj();
	static CObj* CreateObj(float _fX, float _fY);
	static CObj* CreateObj(float _fX, float _fY, MY_MOVEDIRECTION _eDir);
};

template<typename T>
inline Factory<T>::Factory()
{
}

template<typename T>
inline Factory<T>::~Factory()
{
}

template<typename T>
inline CObj* Factory<T>::CreateObj()
{
	CObj* pTmpObj = new T;
	pTmpObj->Initialize();

	return pTmpObj;
}

template<typename T>
inline CObj* Factory<T>::CreateObj(float _fX, float _fY)
{
	CObj* pTmpObj = new T;
	pTmpObj->Initialize();
	pTmpObj->Set_Pos(_fX, _fY);

	return pTmpObj;
}

template<typename T>
inline CObj* Factory<T>::CreateObj(float _fX, float _fY, MY_MOVEDIRECTION _eDir)
{
	CObj* pTmpObj = new T;
	pTmpObj->Initialize();
	pTmpObj->Set_Pos(_fX, _fY);
	pTmpObj->Set_Dir(_eDir);

	return pTmpObj;
}
