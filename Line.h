#pragma once
#include "Vector2.h"
class CLine
{
public:
	CLine();
	CLine(float _startX, float _startY, float _endX, float _endY);
	~CLine();

public:
	void Initiate();
	void Initiate(float _startX, float _startY, float _endX, float _endY);
	void Render(HDC _dc);

	float ReturnY(float _x);

private:
	Vector2 vStartPoint;
	Vector2 vEndPoint;
};

