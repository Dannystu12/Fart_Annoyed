#include "Rectf.h"

Rectf::Rectf(float left, float right, float top, float bottom)
	:
	top(top),
	bottom(bottom),
	left(left),
	right(right)
{
}

Rectf::Rectf(const Vec2 & topLeft, const Vec2 & bottomRight)
	:
	Rectf(topLeft.x, bottomRight.x, topLeft.y, bottomRight.y)
{
}

Rectf::Rectf(const Vec2 & topLeft, float width, float height)
	:
	Rectf(topLeft, topLeft + Vec2(width, height))
{
}

Rectf Rectf::GetExpanded(float offset) const
{
	return Rectf(left - offset, right + offset, top - offset, bottom + offset);
}

Vec2 Rectf::GetCenter() const
{
	return Vec2((left + right) / 2.0f, (top + bottom) / 2.0f);
}

bool Rectf::IsOverlapping(const Rectf & otherRect) const
{
	return bottom >= otherRect.top &&
		top <= otherRect.bottom &&
		left <= otherRect.right &&
		right >= otherRect.left;
}

bool Rectf::IsContainedBy(const Rectf & otherRect) const
{
	return left >= otherRect.left &&
		right <= otherRect.right &&
		top >= otherRect.top &&
		bottom <= otherRect.bottom;
}

Rectf Rectf::FromCenter(const Vec2 & center, float halfWidth, float halfHeight)
{
	const Vec2 half(halfWidth, halfHeight);
	return Rectf(center - half, center + half);
}
