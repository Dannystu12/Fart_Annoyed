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
		gfx.DrawRect(rect.GetExpanded(-padding), c);
	}
}

bool Brick::DoBallCollision(Ball & ball)
{
	if (!isDestroyed && rect.IsOverlapping(ball.GetRect()))
	{
		if (ball.GetPosition().x >= rect.left && ball.GetPosition().x <= rect.right)
		{
			ball.ReboundY();
		}
		else
		{
			ball.ReboundX();
		}
		
		isDestroyed = true;
		return true;
	}
	return false;
}
