#pragma once

#define WINCX 800
#define WINCY 600

struct PosInfo
{
	float fX;
	float fY;
	float fCX;
	float fCY;
};

enum class MY_MOVEDIRECTION
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