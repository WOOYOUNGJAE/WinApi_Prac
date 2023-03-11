#include "stdafx.h"
#include "MainGame.h"

CMainGame::CMainGame()
{
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_dc = GetDC(g_hwnd);
}

void CMainGame::Update()
{
}

void CMainGame::LateUpdate()
{
}

void CMainGame::Render()
{
	Rectangle(m_dc, 0, 0, WINCX, WINCY);


}

void CMainGame::Release()
{
}
