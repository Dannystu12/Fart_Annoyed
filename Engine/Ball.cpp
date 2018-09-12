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
	SpriteCodex::DrawBall(pos, gfx);
}

void Ball::Update(float dt)
{
	pos += vel * dt;
}

bool Ball::DoWallCollision(const Rectf& walls)
{
	bool collision = false;
	const Rectf rect = GetRect();

	if (rect.left < walls.left)
	{
		collision = true;
		pos.x += walls.left - rect.left;
		ReboundX();
	}
	else if (rect.right > walls.right)
	{
		collision = true;
		pos.x -= rect.right - walls.right;
		ReboundX();
	}

	if (rect.top < walls.top)
	{
		collision = true;
		pos.y += walls.top - rect.top;
		ReboundY();
	}
	else if (rect.bottom > walls.bottom)
	{
		collision = true;
		pos.y -= rect.bottom - walls.bottom;
		ReboundY();
	}
	return collision;
}

void Ball::ReboundX()
{
	vel.x *= -1;
}

void Ball::ReboundY()
{
	vel.y *= -1;
}

Rectf Ball::GetRect() const
{
	return Rectf::FromCenter(pos, radius, radius);
}

Vec2 Ball::GetVelocity() const
{
	return vel;
}

Vec2 Ball::GetPosition() const
{
	return pos;
}
