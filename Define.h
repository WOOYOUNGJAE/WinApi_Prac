#pragma once
#include <cmath>
#include "Vector2.h"
#define WINCX 800
#define WINCY 600

//Destroy Zone
#define DESTROYZONE_LEFT 80
#define DESTROYZONE_TOP 60
#define DESTROYZONE_RIGHT WINCX-80
#define DESTROYZONE_BOTTOM WINCY-60/*

struct Vector2
{

	Vector2() {}
	Vector2(float _x, float _y) : fX(_x), fY(_y) {}
	Vector2(Vector2& _rhs) : fX(_rhs.fX), fY(_rhs.fY) {}
	Vector2(Vector2&& _rhs) : fX(_rhs.fX), fY(_rhs.fY) {}

	float fX;
	float fY;

	float magnitude = sqrtf(fX * fX + fY * fY);	

	void Normalize()
	{
		fX /= magnitude;
		fY /= magnitude;
	}

	Vector2 operator =(Vector2&& _vec)
	{
		return Vector2(_vec.fX, _vec.fY);
	}
	Vector2 operator =(Vector2& _vec)
	{
		return Vector2(_vec.fX, _vec.fY);
	}

	Vector2 operator +(Vector2 _vec)
	{
		return Vector2(fX + _vec.fX, fY + _vec.fY);
	}
	Vector2 operator -(Vector2 _vec)
	{
		return Vector2(fX - _vec.fX, fY - _vec.fY);
	}

	template <typename  T>
	Vector2 operator *(T _t)
	{
		return Vector2(fX * _t, fY * _t);
	}

	
	

};
static Vector2 Lerp(Vector2 _Dst, Vector2 _Src, float _fRate)
{
	return _Dst + (_Src - _Dst) * _fRate;
}*/

struct PosInfo
{
	float fX;
	float fY;
	float fCX;
	float fCY;
};

struct AppStateInfo
{
	TCHAR szFPS[32];
	int iFPS;
	DWORD dwTime;
};

enum MY_MOVEDIRECTION
{
	UP,
	RIGHT,
	DOWN,
	LEFT,
	RU,
	LU,
	RD,
	LD,
	DIR_END,
};

enum OBJ_ID 
{
	ID_PLAYER,
	ID_BULLET,
	ID_ENEMY,
	ID_MOUSE,
	ID_SHIELD,
	ID_ROTATION,
	ID_FOLLOWING,
	OBJ_ID_END,
};

enum OBJ_STATE// : int
{
	STATE_START = 0,
	ACTIVE = 1 << 0,
	STATE_END = 1 << 1,
};

enum class TWO_DIR { LEFT, RIGHT, END };

template<typename T>
void SAFE_DELETE(T& tmp)
{
	if (tmp)
	{
		delete tmp;
		tmp = nullptr;
	}
}


struct LinePoint
{
	float fX;
	float fY;

	LinePoint() : fX(0), fY(0) {}
	LinePoint(float _x, float _y) : fX(_x), fY(_y) {}
};

struct MyLine
{
	MyLine(): L_Point{}, R_Point{} {}
	MyLine(LinePoint _L, LinePoint _R)
	{
		L_Point = _L;
		R_Point = _R;
	}

	LinePoint L_Point;
	LinePoint R_Point;
};

extern HWND g_hwnd;
