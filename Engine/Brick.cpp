#include "Brick.h"
#include <assert.h>

Brick::Brick(const Rectf & rect, Color c)
	:
	rect(rect),
	beveler(c)
{
}

void Brick::Draw(Graphics& gfx) const
{
	if (!isDestroyed)
	{
		beveler.DrawBeveledBrick(rect.GetExpanded(-padding), int(bevelSize), gfx);
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
	if (std::signbit(ball.GetVelocity().x) == std::signbit((ball.GetPosition() - GetCenter()).x))
	{
		ball.ReboundY();
	}
	else if (ball.GetPosition().x >= rect.left && ball.GetPosition().x <= rect.right)
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

bool Brick::IsDestroyed() const
{
	return isDestroyed;
}
