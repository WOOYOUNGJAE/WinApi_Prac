#pragma once

#define WINCX 800
#define WINCY 600

enum MOVE_DIR
{
	UP,
	RIGHT,
	DOWN,
	LEFT,
	UR,
	UL,
	DIR_END,
};

enum KEY_INPUT
{
	KEY_UP,
	KEY_RIGHT,
	KEY_DOWN,
	KEY_LEFT,
	KEY_END,
};

extern HWND g_hwnd;

struct Pos_Info
{
	float fX;
	float fY;

	float fHalfHeight;
	float fHalfWidth;
};