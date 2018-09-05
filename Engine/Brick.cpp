#include "Brick.h"

Brick::Brick(const Rectf & rect, Color c)
	:
	rect(rect),
	c(c)
{
}

void Brick::Draw(Graphics& gfx) const
{
	gfx.DrawRect(rect, c);
}
