#pragma once

#define WINCX 800
#define WINCY 600

//Destroy Zone
#define DESTROYZONE_LEFT 80
#define DESTROYZONE_TOP 60
#define DESTROYZONE_RIGHT WINCX-80
#define DESTROYZONE_BOTTOM WINCY-60

struct PosInfo
{
	float fX;
	float fY;
	float fCX;
	float fCY;
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
	OBJ_ID_END,
};

enum OBJ_STATE// : int
{
	STATE_START = 0,
	ACTIVE = 1 << 0,
	STATE_END = 1 << 1,
};

template<typename T>
void SAFE_DELETE(T& tmp)
{
	if (tmp)
	{
		delete tmp;
		tmp = nullptr;
	}
}

extern HWND g_hwnd;
