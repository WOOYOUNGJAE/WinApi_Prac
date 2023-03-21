#pragma once
#include <cmath>

struct Vector2
{

	Vector2() {}
	Vector2(float _x, float _y) : fX(_x), fY(_y) {}
	Vector2(Vector2& _rhs) : fX(_rhs.fX), fY(_rhs.fY) {}
	Vector2(Vector2&& _rhs) : fX(_rhs.fX), fY(_rhs.fY) {}

	float fX;
	float fY;

	float magnitude = sqrtf(fX * fX + fY * fY);

	void Normalize()
	{
		if (fX == 0 || fY == 0)
			return;
		fX /= magnitude;
		fY /= magnitude;
	}

	Vector2 operator =(Vector2&& _vec)
	{
		fX = _vec.fX;
		fY = _vec.fY;
		return *this;
	}
	Vector2 operator =(Vector2& _vec)
	{
		fX = _vec.fX;
		fY = _vec.fY;
		return *this;
	}

	Vector2 operator +(Vector2 _vec)
	{
		/*fX += _vec.fX;
		fY += _vec.fY;
		return *this;*/
		return Vector2(fX + _vec.fX, fY + _vec.fY);
	}
	Vector2 operator -(Vector2 _vec)
	{
		/*fX -= _vec.fX;
		fY -= _vec.fY;
		return *this;*/
		return Vector2(fX - _vec.fX, fY - _vec.fY);
	}

	template <typename  T>
	Vector2 operator *(T _t)
	{
		/*fX *= _t;
		fY *= _t;
		return *this;*/
		return Vector2(fX * _t, fY * _t);
	}




};

namespace Functions
{
	static Vector2 Lerp(Vector2 _Dst, Vector2 _Src, float _fRate)
	{
		return _Dst + (_Src - _Dst) * _fRate;
	}

	static float Inner_Product(Vector2 _Dst, Vector2 _Src)
	{ 
		return _Dst.fX * _Src.fX + _Dst.fX * _Src.fY;
	}
}