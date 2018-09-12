#include "Brick.h"

Brick::Brick(const Rectf & rect, Color c)
	:
	rect(rect),
	c(c)
{
}

void Brick::Draw(Graphics& gfx) const
{
	if (!isDestroyed)
	{
		gfx.DrawRect(rect, c);
	}
}

bool Brick::DoBallCollision(Ball & ball)
{
	if (!isDestroyed && rect.IsOverlapping(ball.GetRect()))
	{
		ball.ReboundY();
		isDestroyed = true;
		return true;
	}
	return false;
}
