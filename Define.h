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

enum class MY_DIRECTION
{
	LEFT,
	UP,
	RIGHT,
	DOWN,
	LU, // Left UP
	RU,
	LD,
	RD,
	END,
};

extern HWND g_hwnd;