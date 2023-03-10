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

template<typename T>
void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}

extern HWND g_hwnd;
