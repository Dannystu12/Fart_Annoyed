#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(const Vec2 & pos, const Vec2 & vel)
	:
	pos(pos),
	vel(vel)
{
}

void Ball::Draw(Graphics & gfx) const
{
	SpriteCodex::DrawBall(pos  + Vec2(radius, radius), gfx);
}
