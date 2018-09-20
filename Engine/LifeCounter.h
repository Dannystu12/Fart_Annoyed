#pragma once
#include "Vec2.h"
#include "Graphics.h"


class LifeCounter
{
public:
	LifeCounter(int lives, const Vec2& pos);
	bool ConsumeLife();
	void Draw(Graphics& gfx) const;
private:
	static constexpr float spacing = 28.0f;
	int lives;
	Vec2 pos;
};