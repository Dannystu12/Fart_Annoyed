#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(const Vec2 & pos, const Vec2 & dir)
	:
	pos(pos),
	startingPos(pos)
{
	SetDirection(dir);
	startingVel = vel;
}

void Ball::Draw(Graphics & gfx) const
{
	SpriteCodex::DrawBall(pos, gfx);
}

void Ball::Update(float dt)
{
	pos += vel * dt;
}

int Ball::DoWallCollision(const Rectf& walls)
{
	// 0 = no collision, 1 = collision with sides/top, 2 = collide with bottom
	int collision = 0;
	const Rectf rect = GetRect();

	if (rect.left < walls.left)
	{
		collision = 1;
		pos.x += walls.left - rect.left;
		ReboundX();
	}
	else if (rect.right > walls.right)
	{
		collision = 1;
		pos.x -= rect.right - walls.right;
		ReboundX();
	}

	if (rect.top < walls.top)
	{
		collision = 1;
		pos.y += walls.top - rect.top;
		ReboundY();
	}
	else if (rect.bottom > walls.bottom)
	{
		collision = 2;
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

void Ball::SetDirection(const Vec2& dir)
{
	vel = dir.GetNormalized() * speed;
}

void Ball::Reset()
{
	pos = startingPos;
	vel = startingVel;
}
