#include "Paddle.h"

Paddle::Paddle(const Vec2 & pos, float halfWidth, float halfHeight)
	:
	pos(pos),
	halfWidth(halfWidth),
	halfHeight(halfHeight),
	exitXFactor(maximumExitRatio / halfWidth),
	fixedZoneHalfWidth(halfWidth * fixedZoneWidthRatio),
	fixedZoneExitX(fixedZoneHalfWidth * exitXFactor),
	startingPos(pos)
{
}

void Paddle::Draw(Graphics& gfx) const
{
	Rectf rect = GetRect();
	gfx.DrawRect(rect, wingColor);
	rect.left += wingWidth;
	rect.right -= wingWidth;
	gfx.DrawRect(rect, color);
}

bool Paddle::DoBallCollision(Ball & ball)
{
	if (GetRect().IsOverlapping(ball.GetRect()) && !cooldown)
	{
		const Rectf rect = GetRect();
		if (std::signbit(ball.GetVelocity().x) == std::signbit((ball.GetPosition() - pos).x)
			|| (ball.GetPosition().x >= rect.left && ball.GetPosition().x <= rect.right))
		{
			Vec2 dir;
			const float xDifference = ball.GetPosition().x - pos.x;
			//modifier  to ensure ball keeps consistent x movement
			int dirModifier = ball.GetVelocity().x > 0 ? 1 : -1;

			if (std::abs(xDifference) < fixedZoneHalfWidth)
			{
				dir = Vec2(dirModifier * fixedZoneExitX, -1.0f);
			}
			else
			{
				dir = Vec2(std::abs(xDifference) * exitXFactor * dirModifier, -1.0f);
			}

			ball.SetDirection(dir);
		}
		else
		{
			ball.ReboundX();
		}
		cooldown = true;
		return true;
	}
	return false;
}

void Paddle::DoWallCollision(const Rectf & walls)
{
	Rectf rect = GetRect();
	if(rect.left < walls.left)
	{
		pos.x += walls.left - rect.left;
	}
	else if (rect.right > walls.right)
	{
		pos.x += walls.right - rect.right;
	}
}

void Paddle::Update(const Keyboard & kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		pos.x -= speed * dt;
	}
	else if (kbd.KeyIsPressed(VK_RIGHT))
	{
		pos.x += speed * dt;
	}
}

Rectf Paddle::GetRect() const
{
	return Rectf::FromCenter(pos, halfWidth, halfHeight);
}

void Paddle::ResetCooldown()
{
	cooldown = false;
}

void Paddle::Reset()
{
	pos = startingPos;
}
