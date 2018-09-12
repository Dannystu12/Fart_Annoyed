#include "Brick.h"
#include <assert.h>

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

bool Brick::CheckBallCollision(const Ball& ball) const
{
	return !isDestroyed && rect.IsOverlapping(ball.GetRect());
}

void Brick::ExecuteBallCollision(Ball & ball)
{
	assert(CheckBallCollision(ball));
	isDestroyed = true;
	if (ball.GetPosition().x >= rect.left && ball.GetPosition().x <= rect.right)
	{
		ball.ReboundY();
	}
	else
	{
		ball.ReboundX();
	}
		
	
}

Vec2 Brick::GetCenter() const
{
	return rect.GetCenter();
}
