#include "Rectf.h"

Rectf::Rectf(float top, float bottom, float left, float right)
	:
	top(top),
	bottom(bottom),
	left(left),
	right(right)
{
}

Rectf::Rectf(const Vec2 & topLeft, const Vec2 & bottomRight)
	:
	Rectf(topLeft.y, bottomRight.y,topLeft.x, bottomRight.x)
{
}

Rectf::Rectf(const Vec2 & topLeft, float width, float height)
	:
	Rectf(topLeft, topLeft + Vec2(width, height))
{
}

bool Rectf::IsOverlapping(const Rectf & otherRect) const
{
	return bottom >= otherRect.top &&
		top <= otherRect.bottom &&
		left <= otherRect.right &&
		right >= otherRect.left;
}
