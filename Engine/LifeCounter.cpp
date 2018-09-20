#define NOMINMAX
#include "LifeCounter.h"
#include "SpriteCodex.h"
#include <algorithm>

LifeCounter::LifeCounter(int lives, const Vec2 & pos)
	:
	lives(lives),
	pos(pos)
{
}

bool LifeCounter::ConsumeLife()
{
	bool hasLife = lives > 0;
	lives = std::max(lives - 1, 0);
	return hasLife;
}

void LifeCounter::Draw(Graphics & gfx) const
{
	const Vec2 offset(spacing, 0.0f);
	for (int i = 0; i < lives; i++)
	{
		SpriteCodex::DrawPoo(pos + offset * float(i), gfx);
	}
}
