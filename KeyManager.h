#pragma once

#define VK_MAX 0XFF

class CKeyManager
{
public:
    CKeyManager();
    ~CKeyManager();

    static CKeyManager* Get_Instance();

    bool Key_Down(int _iKey);
    bool Key_Pressing(int _iKey);
    bool Key_Up(int _iKey);

private:
    static CKeyManager* instance;
    bool m_bKeyStateArr[VK_MAX];
    
};


