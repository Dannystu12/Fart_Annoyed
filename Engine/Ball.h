#pragma once
#include "Vec2.h"
#include "Graphics.h"
class Ball
{
public:
	Ball(const Vec2& pos, const Vec2& vel);
	void Draw(Graphics& gfx) const;
private:
	Vec2 pos;
	Vec2 vel;
	static constexpr float radius = 7.0f;
};