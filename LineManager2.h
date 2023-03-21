#pragma once
#include "Define.h"
#include "Line2.h"


class CLineManager2
{
public:
	CLineManager2();
	~CLineManager2();

public:
	// static
	static CLineManager2* Get_Instance();
	static void Destroy_Instance();

	void Initiate();
	void Update();
	void Render(HDC _dc);
	void Release();

	//bool 
private:
	static CLineManager2* instance;
	vector<CLine2*> m_vecLines;
	LinePoint m_pointArr[(int)TWO_DIR::END];
};

