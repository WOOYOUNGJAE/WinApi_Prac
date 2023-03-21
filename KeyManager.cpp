#include "stdafx.h"
#include "KeyManager.h"

CKeyManager* CKeyManager::instance = nullptr;

CKeyManager::CKeyManager()
{
    ZeroMemory(m_bKeyStateArr, VK_MAX);
}

CKeyManager::~CKeyManager()
{
}

CKeyManager *CKeyManager::Get_Instance()
{
    if (instance == nullptr)
    {
        instance = new CKeyManager;
    }

    return instance;
}

bool CKeyManager::Key_Down(int _iKey)
{
    if (!m_bKeyStateArr[_iKey] &&
        (GetAsyncKeyState(_iKey) & 0x8000))
    {
        m_bKeyStateArr[_iKey] = true;
        return true;
    }

    for (int i = 0; i < VK_MAX; ++i)
    {
        if (m_bKeyStateArr[i] && !(GetAsyncKeyState(i) & 0x8000))
            m_bKeyStateArr[i] = false;
    }

    return false;
}

bool CKeyManager::Key_Pressing(int _iKey)
{
    if (GetAsyncKeyState(_iKey) & 0x8000)
        return true;

    return false;
}

bool CKeyManager::Key_Up(int _iKey)
{
    if (m_bKeyStateArr[_iKey] &&
        !(GetAsyncKeyState(_iKey) & 0x8000))
    {
        m_bKeyStateArr[_iKey] = false;
        return true;
    }

    for (int i = 0; i < VK_MAX; ++i)
    {
        if (!m_bKeyStateArr[i] && (GetAsyncKeyState(i) & 0x8000))
            m_bKeyStateArr[i] = true;
    }

    return false;
}
