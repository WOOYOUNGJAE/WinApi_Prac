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

enum class My_MOVEDIRECTION
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

extern HWND g_hwnd;