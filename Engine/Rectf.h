#pragma once
#include "Vec2.h"

class Rectf
{
public:
	Rectf() = default;
	Rectf(float top, float bottom, float left, float right);
	Rectf(const Vec2& topLeft, const Vec2& bottomRight);
	Rectf(const Vec2& topLeft, float width, float height);
	bool IsOverlapping(const Rectf& otherRect) const;
public:
	float top;
	float bottom;
	float left;
	float right;
};