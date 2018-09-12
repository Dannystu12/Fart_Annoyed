#pragma once
#include "Vec2.h"

class Rectf
{
public:
	Rectf() = default;
	Rectf(float left, float right, float top, float bottom);
	Rectf(const Vec2& topLeft, const Vec2& bottomRight);
	Rectf(const Vec2& topLeft, float width, float height);
	Rectf GetExpanded(float offset) const;
	bool IsOverlapping(const Rectf& otherRect) const;
	static Rectf FromCenter(const Vec2& center, float halfWidth, float halfHeight);
public:
	float top;
	float bottom;
	float left;
	float right;
};