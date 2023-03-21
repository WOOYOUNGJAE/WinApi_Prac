#include "stdafx.h"
#include "Line.h"

CLine::CLine() : vStartPoint(0,0), vEndPoint(0,0)
{
}

CLine::CLine(float _startX, float _startY, float _endX, float _endY):
	vStartPoint(_startX, _startY), vEndPoint(_endX, _endY)
{
}


CLine::~CLine()
{
}

void CLine::Initiate()
{
}

void CLine::Initiate(float _startX, float _startY, float _endX, float _endY)
{
	vStartPoint = Vector2(_startX, _startY);
	vEndPoint = Vector2(_endX, _endY);
}

void CLine::Render(HDC _dc)
{
	MoveToEx(_dc, vStartPoint.fX, vStartPoint.fY, nullptr);
	LineTo(_dc, vEndPoint.fX, vEndPoint.fY);
}

float CLine::ReturnY(float _x)
{
	float fDelta = (vEndPoint.fY - vStartPoint.fY) / (vEndPoint.fX - vStartPoint.fX);

	return fDelta * _x + vStartPoint.fY;
}
